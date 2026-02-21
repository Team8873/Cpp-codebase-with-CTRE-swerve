#include "Commands/IndexerComm.h"

IndexerComm::IndexerComm(Indexer* indexerSubsystem /*,Shooter* shooterSubsystem*/) : m_pIndexerSubsytem{indexerSubsystem}
{
    AddRequirements({m_pIndexerSubsytem});
}

void IndexerComm::Initialize(){
}
void IndexerComm::Execute(){
    m_pIndexerSubsytem->ConveyorOn();
    m_pIndexerSubsytem->UptakeOn();
    /*if (m_shooter1 >= 5000){
        m_pIndexerSubsystem->uptakeOn();
    
    }*/
  
}

void IndexerComm::End(bool interrupted){
    m_pIndexerSubsytem->Stop();
}

bool IndexerComm::IsFinished(){
    return (false);
}

