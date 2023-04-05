#pragma once
// clang-format off

/*
    6_Pack_Std_XXYZ_1_SW_XXYZ_2_SW_RFSD_3_SW_P_4_10V_Spin.h

    Covers all V1 versions V1p0, V1p1, etc

    Part of Grbl_ESP32
    Pin assignments for the ESP32 I2S 6-axis board
    2018    - Bart Dring
    2020    - Mitch Bradley
    2020    - Michiyasu Odaki
    Grbl_ESP32 is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    Grbl is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    You should have received a copy of the GNU General Public License
    along with Grbl_ESP32.  If not, see <http://www.gnu.org/licenses/>.
*/
#define MACHINE_NAME            "6 Pack Std XXYZ 1_SW_XXYZ 2_SW_RFSD 3_SW_P 4_10V_Spin"

#ifdef N_AXIS
        #undef N_AXIS
#endif
#define N_AXIS 3

#ifdef ENABLE_SD_CARD
    #undef ENABLE_SD_CARD
#endif

// === Special Features

// I2S (steppers & other output-only pins)
#define USE_I2S_OUT
#define USE_I2S_STEPS
//#define DEFAULT_STEPPER ST_I2S_STATIC

#define USE_STEPSTICK   // makes sure MS1,2,3 !reset and !sleep are set

#define I2S_OUT_BCK      GPIO_NUM_22
#define I2S_OUT_WS       GPIO_NUM_17
#define I2S_OUT_DATA     GPIO_NUM_21


#define X_STEPPER_MS3           I2SO(3)   // X_CS
#define Y_STEPPER_MS3           I2SO(6)   // Y_CS
#define Z_STEPPER_MS3           I2SO(11)  // Z_CS
#define A_STEPPER_MS3           I2SO(14)  // A_CS
#define B_STEPPER_MS3           I2SO(19)  // B_CS
#define C_STEPPER_MS3           I2SO(22)  // C_CS

#define STEPPER_RESET           GPIO_NUM_19

#define X_DISABLE_PIN           I2SO(0)
#define X_DIRECTION_PIN         I2SO(1)
#define X_STEP_PIN              I2SO(2)

#define X2_DIRECTION_PIN        I2SO(4)
#define X2_STEP_PIN             I2SO(5)
#define X2_DISABLE_PIN          I2SO(7)

#define Y_DISABLE_PIN           I2SO(8)
#define Y_DIRECTION_PIN         I2SO(9)
#define Y_STEP_PIN              I2SO(10)

#define Z_DIRECTION_PIN         I2SO(12)
#define Z_STEP_PIN              I2SO(13)
#define Z_DISABLE_PIN           I2SO(15)


/*
    Socket I/O reference
    The list of modules is here...
    https://github.com/bdring/6-Pack_CNC_Controller/wiki/CNC-I-O-Module-List
    Click on each module to get example for using the modules in the sockets
*/

 
// Socket #1
// #1 GPIO_NUM_33 
// #2 GPIO_NUM_32
// #3 GPIO_NUM_35 (input only)
// #4 GPIO_NUM_34 (input only)


// Socket #2
// #1 GPIO_NUM_2
// #2 GPIO_NUM_25
// #3 GPIO_NUM_39 (input only)
// #4 GPIO_NUM_36 (input only)

// Socket #3
// #1 GPIO_NUM_26
// #2 GPIO_NUM_4
// #3 GPIO_NUM_16
// #4 GPIO_NUM_27


// Socket #4
// #1 GPIO_NUM_14
// #2 GPIO_NUM_13
// #3 GPIO_NUM_15
// #4 GPIO_NUM_12


// Socket #5
// #1 GPIO_NUM_24  (output only)
// #2 GPIO_NUM_25  (output only)
// #3 GPIO_NUM_26  (output only)
// #4 GPIO_NUM_27  (output only)

// Socket #1 Switch Module
#define X_LIMIT_PIN                 GPIO_NUM_33
#define X2_LIMIT_PIN                GPIO_NUM_32
#define Y_LIMIT_PIN                 GPIO_NUM_35
#define Z_LIMIT_PIN                 GPIO_NUM_34
#define DEFAULT_INVERT_LIMIT_PINS   0

// Socket #2 Switch Module
#define CONTROL_RESET_PIN           GPIO_NUM_2
#define CONTROL_FEED_HOLD_PIN       GPIO_NUM_25
#define CONTROL_CYCLE_START_PIN     GPIO_NUM_39
#define CONTROL_SAFETY_DOOR_PIN     GPIO_NUM_36

#ifdef INVERT_CONTROL_PIN_MASK
#undef INVERT_CONTROL_PIN_MASK
#endif
#define INVERT_CONTROL_PIN_MASK B0001 // Mask order Cycle Start | Feed Hold | Reset | Safety Door

// Socket #3 Switch Module
#define PROBE_PIN               GPIO_NUM_26

// Socket #4 0-10V Spin
#define SPINDLE_TYPE            SpindleType::_10V
#define SPINDLE_OUTPUT_PIN      GPIO_NUM_14
#define SPINDLE_FORWARD_PIN     GPIO_NUM_13
#define SPINDLE_REVERSE_PIN     GPIO_NUM_15


// === Default settings
#define DEFAULT_STEP_PULSE_MICROSECONDS I2S_OUT_USEC_PER_PULSE
