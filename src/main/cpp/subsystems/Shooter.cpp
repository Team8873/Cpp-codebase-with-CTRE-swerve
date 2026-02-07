#include "subsystems/Shooter.h"

#pragma region Construction

Shooter::Shooter()
{
    MaxMotorConfig(&m_ShooterRotate,
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

#pragma region Da thing to do things

void Shooter::SetState(){
    m_ShooterRotate.GetClosedLoopController().SetReference(90.0, rev::spark::SparkLowLevel::ControlType::kMAXMotionPositionControl);
}