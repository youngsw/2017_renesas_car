/*
 * PID.h
 *
 *  Created on: 2017��8��24��
 *      Author: Arthur
 */

#ifndef COMPONENTS_PID_H_
#define COMPONENTS_PID_H_

#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include "inc/hw_ints.h"
#include "inc/hw_gpio.h"
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "utils/uartstdio.h"
#include "driverlib/rom.h"
#include "driverlib/qei.h"
#include "driverlib/gpio.h"
#include "driverlib/uart.h"
#include "driverlib/timer.h"
#include "driverlib/sysctl.h"
#include "driverlib/pin_map.h"
#include "driverlib/interrupt.h"

#include "Quadrature_encoder.h"

#define Dest_Left_Vel       1040
#define Dest_Right_Vel      1040

#define DEFAULT_KP          1.50f
#define DEFAULT_KI          0.00f
#define DEFAULT_KD          0.00f

#define DEFAULT_I_MAX       50.0f
#define DEFAULT_OUT_MAX     80.0f
#define DEFAULT_PID_FREQ    50.0f

#define DEFAULT_LPFITER         3.1830e-3
// low pass filter:           0.079577472903393
// f_cut = 1/(2*PI*cutoff_freq)
// f_cut = 2 Hz -> _filter = 79.5774e-3
// f_cut = 10 Hz -> _filter = 15.9155e-3
// f_cut = 15 Hz -> _filter = 10.6103e-3
// f_cut = 20 Hz -> _filter =  7.9577e-3
// f_cut = 25 Hz -> _filter =  6.3662e-3
// f_cut = 30 Hz -> _filter =  5.3052e-3
// f_cut = 50 Hz -> _filter =  3.1830e-3

typedef struct
{
    int dest_left;
    int dest_right;
}Dest_Vel;

typedef struct
{
    float Kp;
    float Ki;
    float Kd;
    float dt;
    float I_MAX;
    float d_LPF;
    float OUT_MAX;
}PID_Params;

typedef struct {
    float Error;
    float LastError;
    float Proportion;
    float Integrator;
    float Derivative;
    float Last_Derivative;
    float PID_OUT;
}PID_Cfg;

extern void PID_Init(void);
extern void Motor_PID(void);
extern void Set_Dest_Vel(int left, int right);
extern void Timer0A_IntHandler(void);

#endif /* COMPONENTS_PID_H_ */