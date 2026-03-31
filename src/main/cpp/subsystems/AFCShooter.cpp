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

    // TalonMotorConfig(&m_shooter1,
    //                 40.0_A,
    //                 true,
    //                 0.1,
    //                 0.0,
    //                 0.0,
    //                 0.0,
    //                 0.0,
    //                 0.0,
    //                 0.0,
    //                 0.0_tps,
    //                 0.0_tr_per_s_sq);

    
    // TalonMotorConfig(&m_shooter2,
    //                 40.0_A,
    //                 true,
    //                 0.1,
    //                 0.0,
    //                 0.0,
    //                 0.0,
    //                 0.0,
    //                   0.0,
    //                 0.0,
    //                 0.0_tps,
    //                 0.0_tr_per_s_sq);
}

void AFCShooter::Periodic(){
    
    m_tx = LimelightHelpers::getTX("limelight-lemold");
    hasTarget = LimelightHelpers::getTV("limelight-lemold");
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

void AFCShooter::AutoLock(double TX){
double tx = std::trunc(TX*100);
double truex = tx/100;
    //m_turretMotor.GetClosedLoopController().GetSetpoint();
    m_turretMotor.Set(-truex * 0.01);
    //m_hoodServo1.Set(0);//-(TA * 20));
    
}

double AFCShooter::GetPosition(){
    return m_turretEncoder.GetPosition();   
}

void AFCShooter::Stop(){
    m_turretMotor.StopMotor();
}