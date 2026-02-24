#include "subsystems/Intake.h"

Intake::Intake()
{
    MaxMotorConfig(&m_intakeMotor,
                    40.0_A,  // Max Amp
                    true,// Brake mode
                    0.1, // Proportional gain
                    0.0, // Integral gain
                    0.0, // Derivative gain ♦♦DON'T TOUCH♦♦ (0.0)
                    0.0, // Static friction
                    0.0, // Velocity constant
                    0.0, // Acceleration constant
                    true); 
    MaxMotorConfig(&m_intakeDeployer,
                    40.0_A,  // Max Amp
                    true,// Brake mode
                    0.1, // Proportional gain
                    0.0, // Integral gain
                    0.0, // Derivative gain ♦♦DON'T TOUCH♦♦ (0.0)
                    0.0, // Static friction
                    0.0, // Velocity constant
                    0.0, // Acceleration constant
                    false);     
}


void Intake::Periodic(){
    auto positionValue = m_intakeStateEncoder.GetPosition();
    double position = positionValue.GetValueAsDouble();
    //double velocityNeo = m_intakeEncoder.GetVelocity();

    frc::SmartDashboard::PutNumber("Intake Encoder", position);
    //frc::SmartDashboard::PutNumber("Intake Velocity", m_intakeEncoder.GetVelocity());
}

void Intake::Disable(){}

void Intake::Deployed(){
    m_intakeDeployer.GetClosedLoopController().SetSetpoint(0.4 /* FIX ME Random number */, rev::spark::SparkLowLevel::ControlType::kPosition);
    
}

void Intake::Stowed(){
     m_intakeDeployer.GetClosedLoopController().SetSetpoint(-0.4 /*FIX ME Random number*/, rev::spark::SparkLowLevel::ControlType::kPosition);
}

void Intake::IntakeOn(){
    
    m_intakeMotor.Set(0.1);

}
void Intake::IntakeOff(){
    
    //m_intakeMotor.StopMotor();
}

void Intake::Stop(){
    //m_intakeMotor.StopMotor();
    //m_intakeDeployer.StopMotor();
}
    