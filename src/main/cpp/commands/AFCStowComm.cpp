#include "commands/AFCStowComm.h"

AFCStowComm::AFCStowComm(AFCIndexer* indexer, AFCIntake* intake) : m_pIndexer{indexer}, m_pIntake{intake}
{
    AddRequirements({m_pIntake});
    AddRequirements({m_pIndexer});
}

void AFCStowComm::Initialize() {
    m_startTime = std::chrono::steady_clock::now();
}

void AFCStowComm::Execute(){
    m_pIntake->Stop();
    frc2::WaitCommand(25_ms);
    m_pIntake->Deployer(0.0);
}

void AFCStowComm::End(bool interrupted){

}

bool AFCStowComm::IsFinished(){
    return (std::chrono::steady_clock::now() - m_startTime) >= std::chrono::milliseconds(500);
}