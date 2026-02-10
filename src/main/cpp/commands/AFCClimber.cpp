#include "subsystems/AFCClimber.h"

#pragma region Constructor

AFCClimber::AFCClimber()
{
    MaxMotorConfig(&m_climberMotor,
                    40.0_A,
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

#pragma region SetState

void AFCClimber::SetState(ClimberStates newState)
{
    if(newState == m_climberState)
        return;
    m_climberState = newState;
    
    auto position = ClimberConstant::ClimberDeployedPos;
    auto speed = 0;

    switch (newState)
    {
        case ClimberStates::stowed:
        {
            position = ClimberConstant::ClimberStowedPos;
            break;
        }

        case ClimberStates::deployed:
        {
            position = ClimberConstant::ClimberDeployedPos;
            break;
        }

        case ClimberStates::manual:
        {
            speed = ClimberConstant::ClimberManual;
        }
    }

    if (newState == ClimberStates::manual)
    {
         m_climberMotor.Set(speed);
    }
    else
    {
        m_climberMotor.GetClosedLoopController().SetReference(position, rev::spark::SparkLowLevel::ControlType::kMAXMotionPositionControl);
    }
   
}
#pragma endregion