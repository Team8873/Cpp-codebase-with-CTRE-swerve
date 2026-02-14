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

double conveyorSpeed = 0;
double uptakeSpeed = 0;

void Indexer::SetConveyorState(conveyorState newConveyorState)
{
if (newConveyorState == m_conveyorState)
        return;

m_conveyorState = newConveyorState;

switch(newConveyorState)
{
    case conveyorState::conveyorOn:
    {
        conveyorSpeed = IndexerConstant::conveyorSpeed;
        break;
    }

    case conveyorState::conveyorOff:
    {
        conveyorSpeed = 0;
        break;
    }
}


m_conveyorMotor.Set(conveyorSpeed);
}

void Indexer::SetUptakeState(uptakeState newUptakeState)
{
    if(newUptakeState == m_uptakeState)
        return;

m_uptakeState = newUptakeState;

switch(newUptakeState)
{
    case uptakeState::uptakeOn:
    {
        uptakeSpeed = IndexerConstant::uptakeSpeed;
        break;
    }
    case uptakeState::uptakeOff:
    {
        uptakeSpeed = 0;
        break;
    }

}
m_uptakeMotor.Set(uptakeSpeed);
}