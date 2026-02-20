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
    frc::SmartDashboard::PutNumber("TX", tx);
    double txNeed = tx * 100.0;
}

void Shooter::Rotate(bool autolock){
    auto positionSignal = m_TurretStateEncoder.GetPosition();
    double pos = positionSignal.GetValueAsDouble();
    m_Turret.Set(tx);
    /*if (autolock == true)
    {
        if (hasTarget == true) 
        {
           m_Turret.Set(0.5); 
          // m_Turret.GetClosedLoopController().SetSetpoint(tx*100, rev::spark::SparkLowLevel::ControlType::kPosition);
        } 
            else 
            {
                m_Turret.Set(0);
           // m_Turret.GetClosedLoopController().SetSetpoint(0, rev::spark::SparkLowLevel::ControlType::kPosition);
            }
    }
        else 
        {
            m_Turret.Set(0);
        // m_Turret.GetClosedLoopController().SetSetpoint(0, rev::spark::SparkLowLevel::ControlType::kPosition);
        }*/
}
 
void Shooter::Disable(){
}

void Shooter::Stop(){

}

#pragma endregion
