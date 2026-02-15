#include "subsystems/AFCIntake.h"
#include <frc/smartdashboard/SmartDashboard.h>

#pragma region Constructor

AFCIntake::AFCIntake()
{
    MaxMotorConfig(&m_intakeMotor,
                    40.0_A,  // Max Amp
                    true,// Brake mode
                    0.1, // Proportional gain
                    0.0, // Integral gain
                    0.0, // Derivative gain ♦♦DON'T TOUCH♦♦
                    0.0, // Static friction
                    0.0, // Velocity constant
                    0.0, // Acceleration constant
                    true); // Onboard encoder
    MaxMotorConfig(&m_intakeDeployer,
                    30.0_A,
                    true,
                    0.1,
                    0.0,
                    0.0,
                    0.0,
                    0.0,
                    0.0,
                    false);

    
}
#pragma endregion

    //m_intakeDeployer.GetClosedLoopController().SetReference(position.value(), rev::spark::SparkLowLevel::ControlType::kMAXMotionPositionControl); // Fix magic number
void AFCIntake::Periodic(){
    auto positionSignal = m_intakeStateEncoder.GetPosition();
    double pos = positionSignal.GetValueAsDouble();
    frc::SmartDashboard::PutNumber("Intake Encoder", pos);
}
void AFCIntake::Disable(){

}
void AFCIntake::Deployer(units::angle::turn_t angleOfDangle){
    auto positionSignal = m_intakeStateEncoder.GetPosition();
    double pos = positionSignal.GetValueAsDouble();
    m_intakeDeployer.GetClosedLoopController().SetSetpoint(pos, rev::spark::SparkLowLevel::ControlType::kPosition);
}
void AFCIntake::IntakeSpeed(){

}
void AFCIntake::Stop(){

}