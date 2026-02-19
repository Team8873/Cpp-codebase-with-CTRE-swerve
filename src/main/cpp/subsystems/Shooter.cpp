#pragma region Includes

#include <frc/smartdashboard/SmartDashboard.h>
#include "subsystems/Shooter.h"

#pragma endregion

#pragma region MaxMotorConfig
//Sets the Max Motor Config for both
Turret::Turret()
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
Shooter::Shooter()
{
    MaxMotorConfig(&m_Shooter,
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

#pragma region SetsTheStatesTurret


void Turret::Periodic(){
    auto positionSignal = m_TurretStateEncoder.GetPosition();
    double pos = positionSignal.GetValueAsDouble();
    frc::SmartDashboard::PutNumber("Turret Encoder", pos);
}

void Turret::Rotate(double AngleOfTurret){
    auto positionSignal = m_TurretStateEncoder.GetPosition();
    double pos = positionSignal.GetValueAsDouble();
    m_Turret.GetClosedLoopController().SetSetpoint(AngleOfTurret, rev::spark::SparkLowLevel::ControlType::kPosition);    
}
void Turret::SetManualSpeedTurret(double speed)
{   
    m_Turret.Set(speed);
} 
void Turret::Disable(){
}

void Turret::Stop(){

}

#pragma endregion
#pragma region SetTheStatesShooter

void Shooter::Periodic(){
    auto positionSignal = m_ShooterStateEncoder.GetPosition();
    double pos = positionSignal.GetValueAsDouble();
    frc::SmartDashboard::PutNumber("Shooter Encoder", pos);
}

void Shooter::SetManualSpeedShooter(double speed)
{   
    m_Shooter.Set(speed);
} 
void Shooter::Disable(){
}

void Shooter::Stop(){

}

#pragma endregion
