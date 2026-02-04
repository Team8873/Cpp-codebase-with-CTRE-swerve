#include "subsystems/AFCIntake.h"

#pragma region Constructor

AFCIntake::AFCIntake()
{
    MaxMotorConfig(&m_intakeMotor,
                    40.0_A,  // Max Amp
                    true,// Brake mode
                    0.1, // Proportional gain
                    0.0, // Integral gain
                    0.0, // Derivative gain ♦♦DON'T TOUCH♦♦
                    0.0, // Static friction
                    0.0, // Velocity constent
                    0.0); // Acceleration constent
                   
}