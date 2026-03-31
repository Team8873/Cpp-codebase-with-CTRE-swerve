#include "commands/AFCShortShootingComm.h"

AFCShortShootingComm::AFCShortShootingComm(AFCIndexer* indexerSubsytem, 
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

void AFCShortShootingComm::Initialize() {
    m_startTime = std::chrono::steady_clock::now();
}

void AFCShortShootingComm::Execute() {
    m_pShootersubsystem->AutoLock(LimelightHelpers::getTX("limelight-lemold"));
    m_pIndexerSubsystem->UptakeOn();
    m_pFlywheelSubsytem->ManualSpeed(-1);
    // m_pFlywheelSubsytem->AutoSpeed(m_pVisionsubsystem->FlySpeed);
}

void AFCShortShootingComm::End(bool interrupted) {
    m_pIndexerSubsystem->Stop(); 
    m_pShootersubsystem->Stop();
}

bool AFCShortShootingComm::IsFinished() {
   return (std::chrono::steady_clock::now() - m_startTime) >= std::chrono::seconds(8);
}