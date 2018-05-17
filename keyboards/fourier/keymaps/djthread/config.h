#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include "../../config.h"
// #include "config_common.h"

/* Use I2C or Serial, not both */

#define USE_SERIAL
// #define USE_I2C


// place overrides here

#define TAPPING_TERM 140
// #define RETRO_TAPPING

// #define MOUSEKEY_DELAY 6
// #define MOUSEKEY_MAX_SPEED 3
// #define MOUSEKEY_TIME_TO_MAX 5

#define MOUSEKEY_INTERVAL 16
#define MOUSEKEY_DELAY 0
#define MOUSEKEY_TIME_TO_MAX 60
#define MOUSEKEY_MAX_SPEED 3
#define MOUSEKEY_WHEEL_DELAY 0


#endif
