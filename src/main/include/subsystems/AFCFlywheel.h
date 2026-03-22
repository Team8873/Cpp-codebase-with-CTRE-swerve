#pragma once

#include <functional>
#include <chrono>

#include <ctre/phoenix6/TalonFX.hpp>

#include <frc2/command/SubsystemBase.h>
#include <frc2/command/CommandPtr.h>
#include <frc2/command/Commands.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <units/angular_velocity.h>

#include "misc/TalonMotorConfig.h"

#include "Constants.h"

class AFCFlywheel : public frc2::SubsystemBase
{
    public:
    explicit AFCFlywheel();
    void Periodic() override;
    void Idle();
    void SpinUp(double Sspeed);
    void AutoSpeed(double Sspeed);
    void ManualSpeed(double Sspeed);
    bool DoneFiring();
    bool Flywheelrpm();
    void Disable();
    void SuperShoot();

    private:
    ctre::phoenix6::hardware::TalonFX m_shooter1{ConstantsCanIds::ShooterMotor1Id};
    ctre::phoenix6::hardware::TalonFX m_shooter2{ConstantsCanIds::ShooterMotor2Id};
    ctre::phoenix6::controls::VelocityVoltage m_velReq{0_tr / 1_s};

    std::chrono::time_point<std::chrono::steady_clock> m_startTime;
    int ballCountAuto = 0;
    double idleCurrent = 5.0;
    bool firingState = false;
    double velocity = 0.0;
};