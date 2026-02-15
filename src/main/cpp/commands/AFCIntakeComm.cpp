#include "commands/AFCIntakeComm.h"

#pragma region Intakestate

AFCIntakeComm::AFCIntakeComm(AFCIntake* intake, units::angle::turn_t angleOfDangle) : m_pIntake{intake}, m_pAngleOfDangle{angleOfDangle} 
{
    AddRequirements({m_pIntake});
}

void AFCIntakeComm::Initialize() {
    m_startTime = std::chrono::steady_clock::now();
    
}

void AFCIntakeComm::Execute(){
    m_pIntake->Deployer(m_pAngleOfDangle);
}

void AFCIntakeComm::End(bool interrupted){
    m_pIntake->Stop();
}
bool AFCIntakeComm::IsFinished() {
    return (std::chrono::steady_clock::now() - m_startTime) >= std::chrono::milliseconds(500);
}