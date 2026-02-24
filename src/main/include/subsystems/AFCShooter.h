#pragma once



#include <functional>

#include <ctre/phoenix6/TalonFX.hpp>
#include <ctre/phoenix6/CANcoder.hpp>

#include <rev/SparkMax.h>
#include <rev/RelativeEncoder.h>

#include <frc2/command/SubsystemBase.h>
#include <frc2/command/CommandPtr.h>
#include <frc/Servo.h>

#include "LimelightHelpers.h"

#include "Constants.h"
#include "misc/MaxMotorConfig.h"
#include "misc/TalonMotorConfig.h"


class AFCShooter : public frc2::SubsystemBase
{
    public:

        explicit AFCShooter();
        void Periodic() override;
        frc2::CommandPtr AutomaticTurret();
        frc2::CommandPtr ManualTurret(double speed);
        void Disable();
        void Stop();

    private:
        

        ctre::phoenix6::hardware::TalonFX m_shooter1{ConstantsCanIds::ShooterMotor1Id};
        ctre::phoenix6::hardware::TalonFX m_shooter2{ConstantsCanIds::ShooterMotor2Id};
        rev::spark::SparkMax m_turretMotor{ConstantsCanIds::TurretMotorId, rev::spark::SparkLowLevel::MotorType::kBrushless};
        rev::spark::SparkRelativeEncoder m_turretEncoder = m_turretMotor.GetEncoder();
        frc::Servo m_hoodServo1{0};
        frc::Servo m_hoodServo2{1};

        double m_tx = 0.0;
        double txNeed = 100.0;
        bool hasTarget = LimelightHelpers::getTV("");


};