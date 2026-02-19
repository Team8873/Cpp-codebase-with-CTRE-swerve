#pragma once

#pragma region Includes

#include <functional>
#include <units/angle.h>

#include <ctre/phoenix6/TalonFX.hpp>
#include <ctre/phoenix6/CANcoder.hpp>

#include <rev/SparkMax.h>

#include <frc2/command/SubsystemBase.h>
#include <frc/smartdashboard/SmartDashboard.h>

#include "Constants.h"
#include "misc/MaxMotorConfig.h"
#pragma endregion

namespace TurretConstant
{
    constexpr auto Turretsoup = 0.25_tr;

    constexpr auto TurretSpeed = 0;
}

class Turret: public frc2::SubsystemBase
{
    public:

        explicit Turret();
        void Periodic() override;
        void Rotate(double AngleOfTurret); //units::angle::turn_t AngleOfTurret
        void SetManualSpeedTurret(double speed);
        void Disable();
        void Stop();
        
        rev::spark::SparkMax m_Turret{ConstantsCanIds::TurretID, rev::spark::SparkLowLevel::MotorType::kBrushless};

    private:

        ctre::phoenix6::hardware::CANcoder m_TurretStateEncoder{ConstantsCanIds::TurretEncoderId};

};

class Shooter: public frc2::SubsystemBase
{
    public:

        explicit Shooter();
        void Periodic() override;
        void SetManualSpeedShooter(double speed);
        void Disable();
        void Stop();
        
        rev::spark::SparkMax m_Shooter{ConstantsCanIds::ShooterID, rev::spark::SparkLowLevel::MotorType::kBrushless};

    private:

        ctre::phoenix6::hardware::CANcoder m_ShooterStateEncoder{ConstantsCanIds::ShooterEncoderId};

};