#include "commands/AFCIndexerComm.h"

AFCIndexerComm::AFCIndexerComm(Indexer* indexerSubsytem, bool OnOff) : m_pIndexerSubsystem{indexerSubsytem}, m_onOff{OnOff}
{
    AddRequirements({m_pIndexerSubsystem});
}

void AFCIndexerComm::Initialize() {
    m_startTime = std::chrono::steady_clock::now();
}

void AFCIndexerComm::Execute() {
    while(m_onOff) {
        m_pIndexerSubsystem->ConveyorOn();
        m_pIndexerSubsystem->UptakeOn();
    } 
   // else{
        //m_pIndexerSubsystem->Stop();
   // }

}

void AFCIndexerComm::End(bool interrupted) {
    m_pIndexerSubsystem->Stop();
}

bool AFCIndexerComm::IsFinished() {
   return (std::chrono::steady_clock::now() - m_startTime) >= std::chrono::milliseconds(500);
}