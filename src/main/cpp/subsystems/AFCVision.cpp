#include "subsystems/AFCVision.h"

AFCVision::AFCVision(){}

void AFCVision::Periodic(){
    m_txTurret = LimelightHelpers::getTX("");
    m_txRobot = LimelightHelpers::getTX("");
    turretHasTarget = LimelightHelpers::getTV("");
    robotHasTarget = LimelightHelpers::getTV("");

    frc::SmartDashboard::PutNumber("Turret X Position", m_txTurret);
    frc::SmartDashboard::PutBoolean("Turret has Target", turretHasTarget);
    frc::SmartDashboard::PutBoolean("Robot has Target", robotHasTarget);
    frc::SmartDashboard::PutNumber("Robot X Position", m_txRobot);
}

double turretFaceCalc(double m_txTurret){
        const double kP = 0.02;
        
        return m_txTurret * kP;
    }

void AFCVision::TurretFace(){
    
}

void AFCVision::Disable(){}