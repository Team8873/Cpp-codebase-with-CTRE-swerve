#include "commands/AFCShootingComm.h"

AFCShootingComm::AFCShootingComm(AFCIndexer* indexerSubsytem, AFCFlywheel* flywheelSubsystem) : m_pIndexerSubsystem{indexerSubsytem}, m_pFlywheelSubsytem{flywheelSubsystem}
{
    AddRequirements({m_pIndexerSubsystem});
    AddRequirements({m_pFlywheelSubsytem});
}

void AFCShootingComm::Initialize() {
    m_startTime = std::chrono::steady_clock::now();
}

void AFCShootingComm::Execute() {
    if(m_pFlywheelSubsytem->Flywheelrpm()){
        m_pIndexerSubsystem->UptakeOn();
    }
     
   
}

void AFCShootingComm::End(bool interrupted) {
    m_pIndexerSubsystem->Stop();
}

bool AFCShootingComm::IsFinished() {
   return (!m_pFlywheelSubsytem->Flywheelrpm());
   
}