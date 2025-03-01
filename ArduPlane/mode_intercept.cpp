#include "mode.h"
#include "Plane.h"
#include <cmath>     // For atan2

void ModeIntercept::update()
{   
    if (!Initialized) {
        pitchDamper.initialize();

        yawDamper.initialize();

        rollDamper.initialize();

        pitchDamperTunable.initialize();
        rollDamperTunable.initialize();
        yawDamperTunable.initialize();


        normalAccController.initialize();
        lateralAccController.initialize();
        guidance.initialize();

        Initialized = true;
    }
}

void ModeIntercept::run()
{

    Vector3f acceleration_commands;
    if (ahrs.get_accel_command(acceleration_commands)) {
        // Successfully retrieved target position
    } else {
        printf("Failed to get acceleration commands.\n");
    }
    

    Vector3f velocity_3d;
    if (ahrs.get_velocity_NED(velocity_3d)) {
        // Successfully retrieved the velocity
    } else {
        printf("Failed to get missile velocity.\n");
    }

    Vector3f gyro_latest = ahrs.get_gyro_latest();

    Vector3f acc_latest = ahrs.get_accel();

    Vector3f missile_position;
    if (ahrs.get_relative_position_NED_origin(missile_position)) {
        // Successfully retrieved the position
    } else {
        printf("Failed to get missile position relative to NED origin.\n");
    }


    // '<Root>/POS_M'
    // float arg_POS_M[3] = {missile_position.x, missile_position.y, missile_position.z};

    // '<Root>/Az_cmd'
    float arg_Az_cmd = acceleration_commands.z;

    // '<Root>/Ay_cmd'
    float arg_Ay_cmd = acceleration_commands.y;

    // guidance.step(arg_POS_M, arg_POS_T, arg_Az_cmd, arg_Ay_cmd);

    // Normal acceleration controller logic
    float arg_Axyz_Body[3] = {acc_latest.x, acc_latest.y, acc_latest.z};
    // float arg_alpha = 0.0f;
    // float arg_beta = 0.0F;
    float arg_pitch_rate_commanded;

    normalAccController.step(arg_Az_cmd, arg_Axyz_Body, arg_pitch_rate_commanded);

    // Lateral acceleration controller logic
    float arg_Ay_body = acc_latest.y;
    float arg_yaw_rate = gyro_latest.z;
    float arg_yaw_rate_command;

    lateralAccController.step(arg_Ay_body, arg_Ay_cmd, arg_yaw_rate, arg_yaw_rate_command, plane.aparm.kp_lac, plane.aparm.ki_lac, plane.aparm.kd_lac);

    // Pitch damper logic
    float pitch_rate_body = gyro_latest.y;
    float speed_magnitude = velocity_3d.length();
    // float arg_Kp_pitch_damper = plane.gain_scaling(0.05f, 0.0005f, 4.0f, speed_magnitude);
    // float arg_Ki_pitch_damper = plane.gain_scaling(0.0f, 0.5f, 1.5f, speed_magnitude);
    // float arg_Kd_pitch_damper = plane.gain_scaling(0.0f, 0.1f, 0.5f, speed_magnitude);

    float arg_elevator_deflection;
    pitchDamper.step(arg_pitch_rate_commanded, pitch_rate_body, speed_magnitude, arg_elevator_deflection);
    // pitchDamperTunable.step(0.0f, pitch_rate_body, arg_Kp_pitch_damper, arg_Ki_pitch_damper, arg_Kd_pitch_damper, arg_elevator_deflection);

    // Yaw damper logic
    float arg_rudder_deflection;
    // float arg_Kp_yaw_damper = plane.gain_scaling(0.1f, 0.083f, 3.0f, speed_magnitude);
    // float arg_Ki_yaw_damper = plane.gain_scaling(5, 0.025f, 1.5f, speed_magnitude);
    // float arg_Kd_yaw_damper = 0.0f;

    yawDamper.step(arg_yaw_rate_command, gyro_latest.z, speed_magnitude, arg_rudder_deflection);
    // yawDamperTunable.step(arg_yaw_rate_command, gyro_latest.z, arg_Kp_yaw_damper, arg_Ki_yaw_damper, arg_Kd_yaw_damper, arg_rudder_deflection);
    // Generate PWM signals
    float elevator_PWM = std::floor((arg_elevator_deflection) * 500 / 7) + 1500;
    float rudder_PWM = std::floor((arg_rudder_deflection) * 500 / 7) + 1500;
    
    SRV_Channels::set_output_pwm(SRV_Channel::k_elevator, elevator_PWM);
    SRV_Channels::set_output_pwm(SRV_Channel::k_rudder, rudder_PWM);

    char msg[200];
    // snprintf(msg, sizeof(msg), "Yaw rate: %.4f, Yaw rate command: %.4f, Ay Body: %.2f, Ay Cmd: %.2f, Rudder: %.2f",
    //          gyro_latest.z, arg_yaw_rate_command, acc_latest.y, arg_Ay_cmd, arg_rudder_deflection);

    // snprintf(msg, sizeof(msg), "Pitch rate: %.4f, Pitch rate command: %.4f, Error: %.4f, Speed: %.2f, Az Body: %.2f, Az Cmd: %.2f, Elevator: %.2f",
    //          gyro_latest.y, arg_pitch_rate_commanded, arg_pitch_rate_commanded-gyro_latest.y, speed_magnitude, acc_latest.z, arg_Az_cmd, arg_elevator_deflection);

    snprintf(msg, sizeof(msg), "Pitch rate: %.4f, Pitch rate command: %.4f, Error: %.4f, Speed: %.2f, Elevator: %.2f",
             gyro_latest.y, 0.0f, 0.0f-gyro_latest.y, speed_magnitude, arg_elevator_deflection);

    // snprintf(msg, sizeof(msg), "Az_cmd: %.4f, Az_body: %.4f, Error: %.4f, Speed: %.2f, Elevator: %.2f",
    //          arg_Az_cmd, acc_latest.z, arg_Az_cmd-acc_latest.z, speed_magnitude, arg_elevator_deflection);

    gcs().send_text(MAV_SEVERITY_INFO, "%s", msg);
}