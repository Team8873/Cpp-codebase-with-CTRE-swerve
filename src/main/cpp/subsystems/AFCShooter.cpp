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
    //                 0.0,
    //                 0.0,
    //                 0.0_tps,
    //                 0.0_tr_per_s_sq);
}

void AFCShooter::Periodic(){
    //auto velocitySignal = m_shooter1.GetVelocity();
    //double velocity = velocitySignal.GetValueAsDouble();
    m_tx = LimelightHelpers::getTX("");
    hasTarget = LimelightHelpers::getTV("");
    turPos = m_turretEncoder.GetPosition();
    //frc::SmartDashboard::PutNumber("Shooter Velocity", velocity);
    frc::SmartDashboard::PutNumber("Lime Target X Position", m_tx);
    frc::SmartDashboard::PutNumber("Turret Target Position", TurretTarget());
    frc::SmartDashboard::PutBoolean("Limelight Has Target", hasTarget);
    frc::SmartDashboard::PutNumber("Turret POS", turPos);
}

void AFCShooter::Disable(){
    Stop();

}
// frc2::CommandPtr AFCShooter::AutomaticTurret() {
//     return this->Run(
//             [this] { 
//                 TurretPOS(TurretTarget());
//             }
//     );
// }

// frc2::CommandPtr AFCShooter::ManualTurret(double speed) {
//     return this->RunOnce(
//                 [this, speed] {
//                    TurretSpeed(speed);
//                 }
//     );
// }

void AFCShooter::TurretPOS(double pos){
    m_turretMotor.GetClosedLoopController().SetSetpoint(pos, rev::spark::SparkLowLevel::ControlType::kPosition);
}

void AFCShooter::TurretSpeed(double speed){
    m_turretMotor.Set(speed);
}

double AFCShooter::TurretTarget(){
    const double kP = 100.0;
    double real_tx = LimelightHelpers::getTX("");
    return (real_tx * kP);
}

void AFCShooter::Stop(){
    m_turretMotor.StopMotor();
}