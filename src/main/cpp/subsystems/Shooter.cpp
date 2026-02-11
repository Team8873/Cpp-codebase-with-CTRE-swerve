#include "subsystems/Shooter.h"

#pragma region Construction

Shooter::Shooter()
{
    MaxMotorConfig(&m_ShooterRotate,
                    30.0_A,
                    true,
                    0.1,
                    0.0,
                    0.0,
                    0.0,
                    0.0,
                    0.0,
                    true);
}
#pragma endregion

#pragma region Da thing to do things

void Shooter::SetState(ShooterRotateStates newState){

    //I *THINK* this starts setting my rotate states (Manual/Automatic)
    if(newState == m_ShooterRotateStates)
     return;
    m_ShooterRotateStates = newState;

    auto position = ShooterRotateConstant::Manual;
    auto speed = 0;

    switch (newState)
    {
        case ShooterRotateStates::Manual:
        break;

    }
    
    m_ShooterRotate.GetClosedLoopController().SetReference(90.0, rev::spark::SparkLowLevel::ControlType::kMAXMotionPositionControl);
}
