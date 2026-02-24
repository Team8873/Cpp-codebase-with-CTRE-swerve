#include "subsystems/Climber.h"

Climber::Climber()
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

void Climber::SetState(ClimberState newState)
{
    if (newState == m_climberState)
        return;
    m_climberState = newState;

    auto position = ClimberState::climberStowed;
    auto speed = 0;

    
}
void Climber::SetManualSpeedUp(bool toggled)
    {
        if (toggled)
            m_climberMotor.Set(-0.05);
        else
            m_climberMotor.Set(0);
    }
void Climber::SetManualSpeedDown(bool toggled)
    {
        if (toggled)
            m_climberMotor.Set(0.05);
        else
            m_climberMotor.Set(0);
    }

