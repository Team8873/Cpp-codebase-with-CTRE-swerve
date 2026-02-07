#include "subsystems/AFCIntake.h"

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

#pragma region SetState

void AFCIntake::SetState(IntakeStates newState)
{
    if(newState == m_intakeState) // Check current state and do nothing if they are the same
        return;

    m_intakeState = newState; // Hold new state

    auto position = IntakeConstant::IntakeStowedAngle; // Determine position based on new state
    auto speed = 0; // Determine speed based on new state

    switch (newState) // Set position and speed based on state
    {
        case IntakeStates::stowed:
        {
            break; // Defualt
        }

        case IntakeStates::deployedOff:
        {
            position = IntakeConstant::IntakeDeployedAngle;
            break;
        }

        case IntakeStates::deployedOn:
        {
            position = IntakeConstant::IntakeDeployedAngle;
            speed = IntakeConstant::IntakeSpeed;
            break;
        }

        
    }
   
    m_intakeDeployer.GetClosedLoopController().SetReference(90.0, rev::spark::SparkLowLevel::ControlType::kMAXMotionPositionControl); // Fix magic number
}