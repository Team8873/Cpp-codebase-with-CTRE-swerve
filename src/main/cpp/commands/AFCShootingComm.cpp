#include "commands/AFCShootingComm.h"

AFCShootingComm::AFCShootingComm(AFCIndexer* indexerSubsytem, 
                                 AFCFlywheel* flywheelSubsystem, 
                                 AFCShooter* shooterSubsystem, 
                                 AFCVision* visionSubsystem)
                                  : m_pIndexerSubsystem{indexerSubsytem}, 
                                    m_pFlywheelSubsytem{flywheelSubsystem}, 
                                    m_pShootersubsystem{shooterSubsystem},
                                    m_pVisionsubsystem{visionSubsystem}
{
    AddRequirements({m_pIndexerSubsystem});
    AddRequirements({m_pFlywheelSubsytem});
    AddRequirements({m_pShootersubsystem});
    AddRequirements({m_pVisionsubsystem});
}

void AFCShootingComm::Initialize() {
    m_startTime = std::chrono::steady_clock::now();
}

void AFCShootingComm::Execute() {
    m_pShootersubsystem->AutoLock(LimelightHelpers::getTX(""));
    m_pIndexerSubsystem->UptakeOn();
    m_pFlywheelSubsytem->ManualSpeed(0);
    // m_pFlywheelSubsytem->AutoSpeed(m_pVisionsubsystem->FlySpeed);

        
    
   
}

void AFCShootingComm::End(bool interrupted) {
    m_pIndexerSubsystem->Stop(); 
    m_pShootersubsystem->Stop();
}

bool AFCShootingComm::IsFinished() {
   return (std::chrono::steady_clock::now() - m_startTime) >= std::chrono::seconds(4);
}