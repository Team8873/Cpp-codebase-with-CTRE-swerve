#pragma once 

#pragma region Includes

#include <functional>
#include <units/angle.h>

#include <ctre/phoenix6/TalonFX.hpp>
#include <ctre/phoenix6/CANcoder.hpp>
#include <rev/SparkMax.h>
#include <frc2/command/SubsystemBase.h>

#include "Constants.h"
//#include "misc/MaxMotorConfig.h"
#pragma endregion

class Shooter : public frc2::SubsystemBase
{
    public:

        explicit Shooter();

    private:

        rev::spark::SparkMax m_ShooterDriver{ConstantsCanIds::ShooterDriverID, rev::spark::SparkLowLevel::MotorType::kBrushless};
        rev::spark::SparkMax m_ShooterRotate{ConstantsCanIds::ShooterRotateID, rev::spark::SparkLowLevel::MotorType::kBrushless};
};
