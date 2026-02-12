#include "commands/AFCClimberComm.h"

#pragma region Climberstates

AFCClimberComm::AFCClimberComm(AFCClimber* climber, ClimberStates state) : m_climber{climber}, m_state{state}
{
    AddRequirements({m_climber});
}

void AFCClimberComm::Initialize() {
    m_climber->SetState(m_state);
}

bool AFCClimberComm::IsFinished() {
    return true;
}