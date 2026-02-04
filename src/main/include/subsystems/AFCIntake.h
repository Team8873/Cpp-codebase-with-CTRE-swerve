#pragma once

#pragma region Includes

#include <functional>

//#include <ctre/phoenix6/TalonFX.hpp>
#include <ctre/phoenix6/CANcoder.hpp>
#include <rev/SparkMax.h>
#include <frc2/command/SubsystemBase.h>

#include "Constants.h"
#include "misc/MaxMotorConfig.h"
#pragma endregion

#pragma region IntakeEnums

enum IntakeStates
{
    stowed,
    deployedOn,
    deployedOff
};
#pragma endregion

#pragma region IntakeConstant
namespace IntakeConstant
{
    // FIX ME PLEASE
    constexpr auto IntakeStowedAngle = 0;
    constexpr auto IntakeDeployedAngle = 0;

    constexpr auto IntakeSpeed = 0;

}
#pragma endregion

class AFCIntake : public frc2::SubsystemBase
{
    public:

        explicit AFCIntake();
    
        void SetState(IntakeStates newState);

        IntakeStates GetState() const { return m_intakeState; }
    private:
        
        rev::spark::SparkMax m_intakeMotor{ConstantsCanIds::IntakeMotorId, rev::spark::SparkLowLevel::MotorType::kBrushless};
        rev::spark::SparkMax m_intakeDeployer{ConstantsCanIds::IntakeDeployerId, rev::spark::SparkLowLevel::MotorType::kBrushless};

        ctre::phoenix6::hardware::CANcoder m_intakeStateEncoder{ConstantsCanIds::IntakeEncoderId};

        IntakeStates m_intakeState = IntakeStates::stowed;


};