#include "commands/AFCJiggleComm.h"



AFCJiggleComm::AFCJiggleComm(AFCIntake* intake) : m_pIntake{intake}
{
    AddRequirements({m_pIntake});
}

void AFCJiggleComm::Initialize() {
    // m_startTime = std::chrono::steady_clock::now();
    
}

void AFCJiggleComm::Execute(){
     
    m_pIntake->JigglePhysics();
    
}

void AFCJiggleComm::End(bool interrupted){
    m_pIntake->Stop();
}

bool AFCJiggleComm::IsFinished(){
    return false;
}