#pragma once


#include <functional>

#include <ctre/phoenix6/TalonFX.hpp>
#include <ctre/phoenix6/CANcoder.hpp>
#include <ctre/phoenix6/TalonFX.hpp>
#include <rev/SparkMax.h>
#include <rev/RelativeEncoder.h>
#include <frc2/command/SubsystemBase.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include "misc/TalonMotorConfig.h"
#include <chrono>
#include <thread>

#include "Constants.h"
#include "misc/MaxMotorConfig.h"

#include <frc2/command/Commands.h>
#include <frc2/command/CommandScheduler.h>
#include <frc2/command/button/RobotModeTriggers.h>
#include <frc2/command/CommandScheduler.h>
#include <frc2/command/InstantCommand.h>
#include <frc2/command/ParallelCommandGroup.h>
#include <frc2/command/RunCommand.h>
#include <frc2/command/SequentialCommandGroup.h>
#include <frc2/command/WaitCommand.h>
#include <frc2/command/WaitUntilCommand.h>
#include <frc2/command/button/Trigger.h>





class AFCIntake : public frc2::SubsystemBase
{
    public:

        explicit AFCIntake();
        void Periodic() override;
        void Disable();
        void Deployer(double pos);
        void JigglePhysics();
        void IntakeSpeed(double speed);
        void DeploySpeed(double speed);
        void Stop();
    
        
    private:
        
        ctre::phoenix6::hardware::TalonFX m_intaker{ConstantsCanIds::IntakerMotorID};
        rev::spark::SparkMax m_intakeMotor{ConstantsCanIds::IntakeMotorId, rev::spark::SparkLowLevel::MotorType::kBrushless};
        rev::spark::SparkMax m_intakeDeployer{ConstantsCanIds::IntakeDeployerId, rev::spark::SparkLowLevel::MotorType::kBrushless};
        rev::spark::SparkRelativeEncoder m_intakeEncoder = m_intakeMotor.GetEncoder();
        rev::spark::SparkRelativeEncoder m_deployerEncoder = m_intakeDeployer.GetEncoder();
        ctre::phoenix6::hardware::CANcoder m_intakeStateEncoder{ConstantsCanIds::IntakeEncoderId};

        std::chrono::time_point<std::chrono::steady_clock> m_startTime;



};