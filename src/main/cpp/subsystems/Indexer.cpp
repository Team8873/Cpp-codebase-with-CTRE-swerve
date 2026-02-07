#include "subsystems/Indexer.h"

#pragma region Constructor

Indexer::Indexer()
{
    MaxMotorConfig(&m_conveyorMotor,
                    30.0_A,  // Max Amp
                    true,// Brake mode
                    0.1, // Proportional gain
                    0.0, // Integral gain
                    0.0, // Derivative gain ♦♦DON'T TOUCH♦♦ (0.0)
                    0.0, // Static friction
                    0.0, // Velocity constant
                    0.0); // Acceleration constant
    MaxMotorConfig(&m_uptakeMotor,
                    40.0_A,  // Max Amp
                    true,// Brake mode
                    0.1, // Proportional gain
                    0.0, // Integral gain
                    0.0, // Derivative gain ♦♦DON'T TOUCH♦♦ (0.0)
                    0.0, // Static friction
                    0.0, // Velocity constant
                    0.0); // Acceleration constant
}
#pragma endregion

#pragma region SetState

void Indexer::SetState(IndexerState newState)
{
if (newState == m_IndexerState)
        return;

m_IndexerState = newState;

auto conveyorSpeed = 0;
auto uptakeSpeed = 0;

switch(newState)
{
    case IndexerState::conveyorOn:
    {
        conveyorSpeed = IndexerConstant::conveyorSpeed;
        break;
    }
    case IndexerState::uptakeOn:
    {
        uptakeSpeed = IndexerConstant::uptakeSpeed;
        break;
    }
    case IndexerState::conveyorOff:
    {
        conveyorSpeed = 0;
        break;
    }
    case IndexerState::uptakeOff:
    {
        uptakeSpeed = 0;
        break;
    }
    case IndexerState::syncOff:
    {
        conveyorSpeed = 0; 
        uptakeSpeed = 0;
        break;
    }
    
}
m_conveyorMotor.Set(conveyorSpeed);
m_uptakeMotor.Set(uptakeSpeed);
}
