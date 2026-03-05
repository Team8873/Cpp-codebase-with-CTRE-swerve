#include "subsystems/AFCShooter.h"


AFCShooter::AFCShooter()
{
    MaxMotorConfig(&m_turretMotor,
                    40.0_A,
                    true,
                    0.004,
                    0.0,
                    0.0,
                    0.0,
                    0.0,
                    0.0,
                    true,
                    false);
}

void AFCShooter::Periodic(){
    
    m_tx = LimelightHelpers::getTX("");
    hasTarget = LimelightHelpers::getTV("");
    turPos = m_turretEncoder.GetPosition();
    frc::SmartDashboard::PutNumber("Lime Target X Position", m_tx);
    frc::SmartDashboard::PutBoolean("Limelight Has Target", hasTarget);
    frc::SmartDashboard::PutNumber("Turret POS", turPos);
    //frc::SmartDashboard::PutNumber("Turret Target Position", TurretTarget());
    //frc::SmartDashboard::PutNumber("Shooter Velocity", velocity);
}

void AFCShooter::Disable(){
    Stop();

}

void AFCShooter::TurretPOS(double pos){
    m_turretMotor.GetClosedLoopController().SetSetpoint(pos, rev::spark::SparkLowLevel::ControlType::kPosition);
}

void AFCShooter::TurretSpeed(double speed){
    m_turretMotor.Set(speed);
}

void AFCShooter::AutoLock(double TX, double TA){
    //m_turretMotor.GetClosedLoopController().GetSetpoint();
    m_turretMotor.Set(TX * 0.01);
    m_hoodServo1.Set(0);//-(TA * 20));
    
}

double AFCShooter::GetPosition(){
    return m_turretEncoder.GetPosition();   
}

void AFCShooter::Stop(){
    m_turretMotor.StopMotor();
}