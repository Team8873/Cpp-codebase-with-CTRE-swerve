#include "commands/AFCIntakeComm.h"

#pragma region Intakestate

AFCIntakeComm::AFCIntakeComm(AFCIntake* intake, IntakeStates state) : m_intake{intake}, m_state{state} 
{
    AddRequirements({m_intake});
}

void AFCIntakeComm::Initialize() {
    m_intake->SetState(m_state);
}

bool AFCIntakeComm::IsFinished() {
    return true;
}