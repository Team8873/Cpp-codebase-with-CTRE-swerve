#include "commands/AFCKickerComm.h"

AFCKickerComm::AFCKickerComm(AFCKicker* kickerSubsystem)
                                : m_pKickerSubsystem{kickerSubsystem}

{
    AddRequirements({m_pKickerSubsystem});
}

void AFCKickerComm::Initialize(){

}

void AFCKickerComm::Execute(){
    m_pKickerSubsystem->KickerOn();
}

void AFCKickerComm::End(bool interrupted){
    m_pKickerSubsystem->Stop();
}

bool AFCKickerComm::IsFinished(){

}