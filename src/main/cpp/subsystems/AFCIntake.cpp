#include "subsystems/AFCIntake.h"




AFCIntake::AFCIntake()
{
    TalonMotorConfig(&m_intaker,
                    40.0_A,
                    false,
                    true,
                    0.4,
                    0.0,
                    0.0,
                    0.0,
                    0.0,
                    0.0,
                    100.0_tps,
                    600.0_tr_per_s_sq);


    
}

    
void AFCIntake::Periodic(){
    // auto positionSignal = m_intakeStateEncoder.GetPosition();
    // double pos = positionSignal.GetValueAsDouble();
    //  double velNeo = m_intakeEncoder.GetVelocity();
    double posNeo = m_deployerEncoder.GetPosition();

    frc::SmartDashboard::PutNumber("Intake Encoder", posNeo);
    // frc::SmartDashboard::PutNumber("Intake Velocity", velNeo);
    
}
void AFCIntake::Disable(){

}
// void AFCIntake::Deployer(double pos){
    
//     m_intakeDeployer.GetClosedLoopController().SetSetpoint(pos, rev::spark::SparkLowLevel::ControlType::kPosition);
// }
void AFCIntake::IntakeSpeed(double speed){
        m_intaker.Set(-speed);
        // m_intakeMotor.Set(speed);
    //m_intakeMotor.GetClosedLoopController().SetSetpoint(speed, rev::spark::SparkLowLevel::ControlType::kVelocity);
}
void AFCIntake::DeploySpeed(double speed){
    m_intakeDeployer.Set(speed);
}
void AFCIntake::Stop(){
    m_intaker.StopMotor();

}