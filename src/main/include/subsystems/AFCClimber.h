#pragma once

#pragma region Includes
#include <string.h>

#include <rev/SparkMax.h>
#include <frc2/command/SubsystemBase.h>
#include <frc/smartdashboard/SmartDashboard.h>

#include "Constants.h"
#include "misc/MaxMotorConfig.h"
#pragma endregion

#pragma region ClimbEnums

enum ClimberStates
{
    climberStowed,
    climberDeployed,
    climberManual
};
#pragma endregion

#pragma region ClimberConstant
namespace ClimberConstant
{
    // Placeholders
    constexpr auto ClimberStowedPos = 0.0;
    constexpr auto ClimberDeployedPos = 1000.0;
    constexpr auto ClimberManual = 0.0;
} 
#pragma endregion

class AFCClimber : public frc2::SubsystemBase
{
    public:

        explicit AFCClimber();

        void SetState(ClimberStates newState);
        void SetPosClimber(double pos);

        void SetManualSpeed(double speed);

        ClimberStates GetState() const { return m_climberState; }
    private:

        rev::spark::SparkMax m_climberMotor{ConstantsCanIds::ClimberMotor,rev::spark::SparkLowLevel::MotorType::kBrushless};

        ClimberStates m_climberState = ClimberStates::climberStowed;

};