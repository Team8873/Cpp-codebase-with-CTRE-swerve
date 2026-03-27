#include "Commands/ShooterComm.h"

ShooterComm::ShooterComm(Shooter* ShooterSubsystem) : m_pShooterSubsystem{ShooterSubsystem}
{
    AddRequirements({m_pShooterSubsystem});
}

void ShooterComm::Initialize(){
}

void ShooterComm::Execute(){
}

void ShooterComm::End(bool interrupted){
    m_pShooterSubsystem->Stop();
}

bool ShooterComm::IsFinished(){
    return (std::chrono::steady_clock::now() - m_startTime) >= std::chrono::milliseconds(5000);
}