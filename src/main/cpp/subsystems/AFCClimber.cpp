#include "subsystems/AFCClimber.h"


AFCClimber::AFCClimber()
{
    MaxMotorConfig(&m_climberMotor,
                    40.0_A,
                    true,
                    0.1,
                    0.0,
                    0.0,
                    0.0,
                    0.0,
                    0.0,
                    true,
                    true);
}


void AFCClimber::Periodic(){
    double posNeo = m_climberEncoder.GetPosition();

    frc::SmartDashboard::PutNumber("Climber Encoder", posNeo);
}
void AFCClimber::Disable(){

}

void AFCClimber::ClimberDown()
{
    m_climberMotor.GetClosedLoopController().SetSetpoint(0.0, rev::spark::SparkLowLevel::ControlType::kPosition);
    
}

void AFCClimber::ClimberUp()
{
    m_climberMotor.GetClosedLoopController().SetSetpoint(1000, rev::spark::SparkLowLevel::ControlType::kPosition);
}

void AFCClimber::SetManualSpeed(double speed)
{    
    m_climberMotor.Set(speed);
}
void AFCClimber::Stop(){
    m_climberMotor.StopMotor();
}