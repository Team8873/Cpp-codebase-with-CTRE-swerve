#pragma once 

#pragma region Includes

#include <functional>
#include <units/angle.h>

#include <ctre/phoenix6/TalonFX.hpp>
#include <ctre/phoenix6/CANcoder.hpp>
#include <rev/SparkMax.h>
#include <frc2/command/SubsystemBase.h>

#include "Constants.h"
#include "misc/MaxMotorConfig.h"
#pragma endregion

enum ShooterRotateStates
{
    Manual,
    Automatic
};

namespace ShooterRotateConstant
{
    //Placeholer
    constexpr auto Manual = 0;
    constexpr auto Automatic = 0;
};

class Shooter : public frc2::SubsystemBase
{
    public:

        explicit Shooter();

        void SetState(ShooterRotateStates newState);

        ShooterRotateStates GetState() const { return m_ShooterRotateStates; }
    private:

        rev::spark::SparkMax m_ShooterDriver{ConstantsCanIds::ShooterDriverID, rev::spark::SparkLowLevel::MotorType::kBrushless};
        rev::spark::SparkMax m_ShooterRotate{ConstantsCanIds::ShooterRotateID, rev::spark::SparkLowLevel::MotorType::kBrushless};

        ShooterRotateStates m_ShooterRotateStates = ShooterRotateStates::Manual;

};