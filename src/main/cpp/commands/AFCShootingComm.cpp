#include "commands/AFCShootingComm.h"

AFCShootingComm::AFCShootingComm(AFCIndexer* indexerSubsytem, 
                                 AFCFlywheel* flywheelSubsystem, 
                                 AFCShooter* shooterSubsystem, 
                                 AFCVision* visionSubsystem,
                                 AFCKicker* kickerSubsystem)
                                  : m_pIndexerSubsystem{indexerSubsytem}, 
                                    m_pFlywheelSubsytem{flywheelSubsystem}, 
                                    m_pShootersubsystem{shooterSubsystem},
                                    m_pVisionsubsystem{visionSubsystem},
                                    m_pKickerSubsystem{kickerSubsystem}
{
    AddRequirements({m_pIndexerSubsystem});
    AddRequirements({m_pFlywheelSubsytem});
    AddRequirements({m_pShootersubsystem});
    AddRequirements({m_pVisionsubsystem});
    AddRequirements({m_pKickerSubsystem});
}

void AFCShootingComm::Initialize() {
    m_startTime = std::chrono::steady_clock::now();
}

void AFCShootingComm::Execute() {
    m_pShootersubsystem->TurretPOS(m_pVisionsubsystem->Saved_Turret_Angle);
    m_pFlywheelSubsytem->AutoSpeed(m_pVisionsubsystem->Saved_Flywheel_Speed);
    m_pIndexerSubsystem->UptakeOn();
    m_pKickerSubsystem->KickerJitter();


}

void AFCShootingComm::End(bool interrupted) {
    m_pIndexerSubsystem->Stop(); 
    m_pShootersubsystem->Stop();
    m_pShootersubsystem->Stop();
    m_pKickerSubsystem->Stop();
}

bool AFCShootingComm::IsFinished() {
   return (std::chrono::steady_clock::now() - m_startTime) >= std::chrono::seconds(20);
}