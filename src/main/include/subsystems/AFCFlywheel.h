#pragma once

#include <functional>

#include <ctre/phoenix6/TalonFX.hpp>

#include <frc2/command/SubsystemBase.h>
#include <frc2/command/CommandPtr.h>
#include <frc2/command/Commands.h>
#include <frc/smartdashboard/SmartDashboard.h>

#include "misc/TalonMotorConfig.h"

#include "Constants.h"

class AFCFlywheel : public frc2::SubsystemBase
{
    public:
    explicit AFCFlywheel();
    void Periodic() override;
    void Idle();
    void SpinUp(double Sspeed);
    bool Flywheelrpm();
    void Disable();

    private:
    ctre::phoenix6::hardware::TalonFX m_shooter1{ConstantsCanIds::ShooterMotor1Id};
    ctre::phoenix6::hardware::TalonFX m_shooter2{ConstantsCanIds::ShooterMotor2Id};

    double velocity = 0.0;
};