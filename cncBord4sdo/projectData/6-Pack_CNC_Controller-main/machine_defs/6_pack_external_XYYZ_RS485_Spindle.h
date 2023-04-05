#pragma once
// clang-format off

/*
   6_pack_external_XYYZ_RS485_Spin.h


    Part of Grbl_ESP32
    Pin assignments for the ESP32 I2S 6-axis board

    2021-03-07  Bart Dring for Basel K. A.
    
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


    6 Pack Jumpers for External Drivers
    The only jumper you set is the Vcc on 5V
    Stallguard jumpers must not be connected
    MS/SPI Do not need to be installed. It is OK to put them oonm the MS side
    TMC5160 Is does not matter if this is installed or not on any side.


*/
#define MACHINE_NAME            "6 Pack External XYYZ RS485 Spin"

#define N_AXIS 3

// === Special Features

// I2S (steppers & other output-only pins)
#define USE_I2S_OUT
#define USE_I2S_STEPS
//#define DEFAULT_STEPPER ST_I2S_STATIC

#define I2S_OUT_BCK             GPIO_NUM_22
#define I2S_OUT_WS              GPIO_NUM_17
#define I2S_OUT_DATA            GPIO_NUM_21


// Motor Socket #1
#define X_DISABLE_PIN           I2SO(0)
#define X_DIRECTION_PIN         I2SO(1)
#define X_STEP_PIN              I2SO(2)

// Motor Socket #2
#define Y_DIRECTION_PIN         I2SO(4)
#define Y_STEP_PIN              I2SO(5)
#define Y_DISABLE_PIN           I2SO(7)

// Motor Socket #3
#define Y2_DISABLE_PIN          I2SO(8)
#define Y2_DIRECTION_PIN        I2SO(9)
#define Y2_STEP_PIN             I2SO(10)


// Motor Socket #4
#define Z_DIRECTION_PIN         I2SO(12)
#define Z_STEP_PIN              I2SO(13)
#define z_DISABLE_PIN           I2SO(15)

/*
// Motor Socket #5
#define B_DISABLE_PIN           I2SO(16)
#define B_DIRECTION_PIN         I2SO(17)
#define B_STEP_PIN              I2SO(18)
#define B_STEPPER_MS3           I2SO(19) 

// Motor Socket #5
#define C_DIRECTION_PIN         I2SO(20)
#define C_STEP_PIN              I2SO(21)
#define C_STEPPER_MS3           I2SO(22)
#define C_DISABLE_PIN           I2SO(23)
*/

/*
    Socket I/O reference
    The list of modules is here...
    https://github.com/bdring/6-Pack_CNC_Controller/wiki/CNC-I-O-Module-List
    Click on each module to get example for using the modules in the sockets


Socket #1
#1 GPIO_NUM_33 
#2 GPIO_NUM_32
#3 GPIO_NUM_35 (input only)
#4 GPIO_NUM_34 (input only)

Socket #2
#1 GPIO_NUM_2
#2 GPIO_NUM_25
#3 GPIO_NUM_39 (input only)
#4 GPIO_NUM_36 (input only)

Socket #3
#1 GPIO_NUM_26
#2 GPIO_NUM_4
#3 GPIO_NUM_16
#4 GPIO_NUM_27

Socket #4
#1 GPIO_NUM_14
#2 GPIO_NUM_13
#3 GPIO_NUM_15
#4 GPIO_NUM_12

Socket #5
#1 I2SO(24)  (output only)
#2 I2SO(25)  (output only)
#3 I2SO26)  (output only)

*/


// 4x Input Module in Socket #1
// https://github.com/bdring/6-Pack_CNC_Controller/wiki/4x-Switch-Input-module
#define X_LIMIT_PIN             GPIO_NUM_33  
#define Y_LIMIT_PIN             GPIO_NUM_32
#define Y2_LIMIT_PIN            GPIO_NUM_35 
#define Z_LIMIT_PIN             GPIO_NUM_34 

// // 4x Switch Input module  in socket #2
// // // https://github.com/bdring/6-Pack_CNC_Controller/wiki/4x-Switch-Input-module
#define PROBE_PIN               GPIO_NUM_2

// Example 5V output CNC module in socket #3
// https://github.com/bdring/6-Pack_CNC_Controller/wiki/4x-5V-Buffered-Output-Module
#define USER_DIGITAL_PIN_0            GPIO_NUM_26  // M62 P0 (on) M63 P0 (off)
#define USER_DIGITAL_PIN_1            GPIO_NUM_4   // 
#define USER_ANALOG_PIN_0             GPIO_NUM_16  // M67 E0 Qnn (nn=0-100 percent)
#define USER_ANALOG_PIN_1             GPIO_NUM_27  // 

// RS485 Modbus In socket #4
// https://github.com/bdring/6-Pack_CNC_Controller/wiki/RS485-Modbus-Module
#define SPINDLE_TYPE            SpindleType::HUANYANG // default, check actual $Spindle/Type Setting
#define VFD_RS485_TXD_PIN        GPIO_NUM_14
#define VFD_RS485_RTS_PIN        GPIO_NUM_13
#define VFD_RS485_RXD_PIN        GPIO_NUM_15


// ================= Setting Defaults ==========================
// see wiki https://github.com/bdring/Grbl_Esp32/wiki/External-Stepper-Drivers
#define DEFAULT_STEP_ENABLE_DELAY        5 // how long after enable do we wait for 
#define DEFAULT_STEP_PULSE_MICROSECONDS  4 // length of step pulse. Must be greater than I2S_OUT_USEC_PER_PULSE (4) with I2S
#define STEP_PULSE_DELAY                 6 // gap between enable and dir changes before step

//#define DEFAULT_STEPPING_INVERT_MASK     (bit(X_AXIS) | bit(Y_AXIS) | bit(Z_AXIS))
//#define DEFAULT_DIRECTION_INVERT_MASK    (bit(X_AXIS) | bit(Y_AXIS) | bit(Z_AXIS))
//#define DEFAULT_INVERT_ST_ENABLE         false

#define DEFAULT_INVERT_LIMIT_PINS       0
#define DEFAULT_INVERT_PROBE_PIN        0

