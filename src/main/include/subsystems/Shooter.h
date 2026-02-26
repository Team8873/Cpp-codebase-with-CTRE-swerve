#pragma once

#pragma region Includes

#include <functional>
#include <units/angle.h>
#include <string.h>

#include <ctre/phoenix6/TalonFX.hpp>
#include <ctre/phoenix6/CANcoder.hpp>

#include <rev/SparkMax.h>

#include <frc2/command/SubsystemBase.h>
#include <frc/smartdashboard/SmartDashboard.h>

#include "Constants.h"
#include "misc/MaxMotorConfig.h"

#pragma endregion

#pragma region Constants

namespace TurretConstant
//placeholders
{
    constexpr auto Turretsoup = 0.25_tr;
    constexpr auto TurretSpeed = 0;
}

#pragma endregion

#pragma region Class Turret

class Turret: public frc2::SubsystemBase
{
    public:

        explicit Turret();
            void Periodic() override;
                void Rotate(double AngleOfTurret); //units::angle::turn_t AngleOfTurret
                    void SetManualSpeedTurret(double speed);
                        void Reset();    
                            void Disable();
                                void Stop();
        
        rev::spark::SparkMax m_Turret{ConstantsCanIds::TurretID, rev::spark::SparkLowLevel::MotorType::kBrushless};

    private:

        ctre::phoenix6::hardware::CANcoder m_TurretStateEncoder{ConstantsCanIds::TurretEncoderId};

};

#pragma endregion

#pragma region Class Shooter

class Shooter: public frc2::SubsystemBase
{
    public:

        explicit Shooter();
            void Periodic() override;
                void SetSpeedShooter(double speed);
                    void Disable();
                        void Stop();
        
        rev::spark::SparkMax m_Shooter{ConstantsCanIds::ShooterID, rev::spark::SparkLowLevel::MotorType::kBrushless};

    private:

        ctre::phoenix6::hardware::CANcoder m_ShooterStateEncoder{ConstantsCanIds::ShooterEncoderId};

};