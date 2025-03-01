#pragma once

#include <AP_Param/AP_Param.h>

/*
  common parameters for fixed wing aircraft
*/
struct AP_FixedWing {
    AP_Int8 throttle_min;
    AP_Int8 throttle_max;
    AP_Int8 throttle_slewrate;
    AP_Int8 throttle_cruise;
    AP_Int8 takeoff_throttle_max;
    AP_Int16 airspeed_min;
    AP_Int16 airspeed_max;
    AP_Float airspeed_cruise;
    AP_Float min_groundspeed;
    AP_Int8  crash_detection_enable;
    AP_Float roll_limit;
    AP_Float pitch_limit_max;
    AP_Float pitch_limit_min;
    AP_Int8  autotune_level;
    AP_Int32 autotune_options;
    AP_Int8  stall_prevention;
    AP_Int16 loiter_radius;
    AP_Float takeoff_throttle_max_t;
    AP_Float kp_nac;
    AP_Float ki_nac;
    AP_Float kd_nac;
    AP_Float kd_lac;
    AP_Float kp_lac;
    AP_Float ki_lac;

    AP_Float kp_pd;
    AP_Float ki_pd;
    AP_Float kd_pd;

    AP_Float kp_yd;
    AP_Float ki_yd;
    AP_Float kd_yd;

    AP_Float kp_rd;
    AP_Float ki_rd;
    AP_Float kd_rd;

    AP_Float scl_lwr_pd;
    AP_Float scl_upr_pd;

    AP_Float scl_lwr_rd;
    AP_Float scl_upr_rd;

    AP_Float scl_lwr_yd;
    AP_Float scl_upr_yd;

    struct Rangefinder_State {
        bool in_range:1;
        bool have_initial_reading:1;
        bool in_use:1;
        float initial_range;
        float correction;
        float initial_correction;
        float last_stable_correction;
        uint32_t last_correction_time_ms;
        uint8_t in_range_count;
        float height_estimate;
        float last_distance;
    };


    // stages of flight
    enum class FlightStage {
        TAKEOFF       = 1,
        VTOL          = 2,
        NORMAL        = 3,
        LAND          = 4,
        ABORT_LANDING = 7
    };
};
