#pragma once

#include <rev/SparkMax.h>
#include <frc2/command/SubsystemBase.h>
#include "Constants.h"
#include "misc/MaxMotorConfig.h"


enum ClimberState
{
    climberStowed,
    climberDeployed,
    climberManual,
};

namespace ClimberConstants
{
    constexpr  double climberStowed = 0.0;
    constexpr double climberDeployed = 999.0;
    constexpr double climberManual = 0.0;
}

class Climber : public frc2::SubsystemBase
{
    public:
        explicit Climber();

        void SetState(ClimberState newState);
        void SetPosition(double position);

        void SetManualSpeedUp(bool toggled);
        void SetManualSpeedDown(bool toggled);

        ClimberState GetState() const {return m_climberState;}
    private:
        rev::spark::SparkMax m_climberMotor{ConstantsCanIds::ClimberMotor, rev::spark::SparkLowLevel::MotorType::kBrushless};

        ClimberState m_climberState = ClimberState::climberStowed;

};