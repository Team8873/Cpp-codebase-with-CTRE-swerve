#include "subsystems/AFCShooter.h"
#include <frc2/command/Commands.h>
#include <frc/smartdashboard/SmartDashboard.h>

AFCShooter::AFCShooter()
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

void AFCShooter::Periodic(){
    auto velocitySignal = m_shooter1.GetVelocity();
    double velocity = velocitySignal.GetValueAsDouble();
    m_tx = LimelightHelpers::getTX("");
    bool hasTarget = LimelightHelpers::getTV("");
    double turPos = m_turretEncoder.GetPosition();
    frc::SmartDashboard::PutNumber("Shooter Velocity", velocity);
    frc::SmartDashboard::PutNumber("Lime Target X Position", m_tx);
    frc::SmartDashboard::PutBoolean("Limelight Has Target", hasTarget);
    frc::SmartDashboard::PutNumber("Turret POS", turPos);
}

void AFCShooter::Disable(){

}
frc2::CommandPtr AFCShooter::AutomaticTurret() {
    return this->RunOnce([this] { m_turretMotor.GetClosedLoopController().SetSetpoint(txNeed, rev::spark::SparkLowLevel::ControlType::kPosition);});
}

frc2::CommandPtr AFCShooter::ManualTurret(double speed) {
    return this->Run([this, speed] { m_turretMotor.Set(speed);});
}
void AFCShooter::Stop(){
    m_turretMotor.StopMotor();
}