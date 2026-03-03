#include "subsystems/AFCVision.h"

AFCVision::AFCVision(){}

void AFCVision::Periodic(){
    m_txRobot = LimelightHelpers::getTX("");
    m_txTurret = LimelightHelpers::getTX("");
    turretHasTarget = LimelightHelpers::getTV("");
    robotHasTarget = LimelightHelpers::getTV("");
    
    frc::SmartDashboard::PutNumber("Turret X Position", m_txTurret);
    frc::SmartDashboard::PutBoolean("Turret has Target", turretHasTarget);
    frc::SmartDashboard::PutBoolean("Robot has Target", robotHasTarget);
    frc::SmartDashboard::PutNumber("Robot X Position", m_txRobot);
}

double AFCVision::turretFaceCalc(){
    const double kP = 0.02;
        
        return LimelightHelpers::getTX("") * kP;
    }

void AFCVision::TurretFace(){
    
}

void AFCVision::Disable(){}