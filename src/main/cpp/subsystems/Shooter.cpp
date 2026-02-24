#include "subsystems/Shooter.h"



Shooter::Shooter()
{
    MaxMotorConfig(&m_turretMotor,
                    40.0_A,
                    true,
                    0.75,
                    0.0,
                    0.0,
                    0.0,
                    0.0,
                    0.0,
                    true);

    TalonMotorConfig(&m_shooter1,
                    40.0_A,
                    true,
                    0.1,
                    0.0,
                    0.0,
                    0.0,
                    0.0,
                    0.0,
                    0.0,
                    0.0_tps,
                    0.0_tr_per_s_sq);

    
    TalonMotorConfig(&m_shooter2,
                    40.0_A,
                    true,
                    0.1,
                    0.0,
                    0.0,
                    0.0,
                    0.0,
                    0.0,
                    0.0,
                    0.0_tps,
                    0.0_tr_per_s_sq);
}

void Shooter::Periodic(){
    auto velocitySignal = m_shooter1.GetVelocity();
    double velocity = velocitySignal.GetValueAsDouble();
    m_tx = LimelightHelpers::getTX("");
    hasTarget = LimelightHelpers::getTV("");
    turPos = m_turretEncoder.GetPosition();
    frc::SmartDashboard::PutNumber("Shooter Velocity", velocity);
    frc::SmartDashboard::PutNumber("Lime Target X Position", m_tx);
    frc::SmartDashboard::PutNumber("Turret Target Position", TurretTarget());
    frc::SmartDashboard::PutBoolean("Limelight Has Target", hasTarget);
    frc::SmartDashboard::PutNumber("Turret POS", turPos);
}

void Shooter::Disable(){
    Stop();

}
frc2::CommandPtr Shooter::AutoTurret() {
    return this->Run(
            [this] { 
                TurretPOS(TurretTarget());
            }
    );
}

frc2::CommandPtr Shooter::ManualTurret(double Tspeed) {
    return this->Run(
                [this, Tspeed] {
                   TurretSpeed(Tspeed);
                }
    );
}

void Shooter::TurretPOS(double Tpos){
    m_turretMotor.GetClosedLoopController().SetSetpoint(Tpos, rev::spark::SparkLowLevel::ControlType::kPosition);
}

void Shooter::TurretSpeed(double tspeed){
    m_turretMotor.Set(tspeed);
}

double Shooter::TurretTarget(){
    const double kP = 100.0;
    double LLtx = LimelightHelpers::getTX("");
    return (LLtx * kP);
}

void Shooter::Stop(){
    m_turretMotor.StopMotor();
}