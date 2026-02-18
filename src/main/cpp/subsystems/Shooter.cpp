#pragma region Includes

#include <frc/smartdashboard/SmartDashboard.h>
#include "subsystems/Shooter.h"

#pragma endregion

#pragma region MaxMotorConfig
//Sets the Max Motor Config
Shooter::Shooter()
{
    MaxMotorConfig(&m_Turret,
                    30.0_A,
                    true,
                    0.1,
                    0.0,
                    0.0,
                    0.0,
                    0.0,
                    0.0,
                    true);
}
#pragma endregion

#pragma region SetsTheStates

void Shooter::Periodic(){
    auto positionSignal = m_TurretStateEncoder.GetPosition();
    double pos = positionSignal.GetValueAsDouble();
    frc::SmartDashboard::PutNumber("Turret Encoder", pos);
}

void Shooter::Rotate(double AngleOfTurret){
    auto positionSignal = m_TurretStateEncoder.GetPosition();
    double pos = positionSignal.GetValueAsDouble();
    m_Turret.GetClosedLoopController().SetSetpoint(AngleOfTurret, rev::spark::SparkLowLevel::ControlType::kPosition);    
}
void Shooter::SetManualSpeed(double speed)
{   
    m_Turret.Set(speed);
} 
void Shooter::Disable(){
}

void Shooter::Stop(){

}

#pragma endregion
