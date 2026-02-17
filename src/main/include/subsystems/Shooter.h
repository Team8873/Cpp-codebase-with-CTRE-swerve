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

namespace TurretConstant

{}

class Shooter: public frc2::SubsystemBase
{
    public:

        explicit Shooter();
        void Periodic() override;
        void Rotate(double AngleOfTurret); //units::angle::turn_t AngleOfTurret
        void Disable();
        void Stop();

    private:

        rev::spark::SparkMax m_Shooter{ConstantsCanIds::ShooterID, rev::spark::SparkLowLevel::MotorType::kBrushless};
        rev::spark::SparkMax m_Turret{ConstantsCanIds::TurretID, rev::spark::SparkLowLevel::MotorType::kBrushless};

        ctre::phoenix6::hardware::CANcoder m_TurretStateEncoder{ConstantsCanIds::TurretEncoderId};

};