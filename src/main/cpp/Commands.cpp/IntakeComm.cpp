#include "Commands/IntakeComm.h"

IntakeComm::IntakeComm(Intake* intakeSubsytem) : m_pIntakeSubsytem{intakeSubsytem}
{
    AddRequirements({m_pIntakeSubsytem});

}

void IntakeComm::Initialize(){}

void IntakeComm::Execute(){
    m_pIntakeSubsytem->Deployed();
    //frc2::WaitCommand(25_ms);
    m_pIntakeSubsytem->IntakeOn();
}
void IntakeComm::End(bool interrupted){
    m_pIntakeSubsytem->Stop();
}
    
bool IntakeComm::IsFinished(){
       return (std::chrono::steady_clock::now() - m_startTime) >= std::chrono::milliseconds(5000);
    // return (m_pIntakeSubsytem->m_intakeEncoder.GetPosition() >= 0.4 /*FIX ME Random Number */);
}
