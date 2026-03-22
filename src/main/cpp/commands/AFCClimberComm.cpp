#include "commands/AFCClimberComm.h"


AFCClimberComm::AFCClimberComm(AFCClimber* climber) : m_pClimber{climber}
{
    AddRequirements({m_pClimber});
}

void AFCClimberComm::Initialize() {
    m_startTime = std::chrono::steady_clock::now();  
}

void AFCClimberComm::Execute() {
    m_pClimber->ClimberDown();
}
void AFCClimberComm::End(bool interrupted){
    m_pClimber->Stop();
}

bool AFCClimberComm::IsFinished() {
    return (std::chrono::steady_clock::now() - m_startTime) >= std::chrono::milliseconds(500);
}