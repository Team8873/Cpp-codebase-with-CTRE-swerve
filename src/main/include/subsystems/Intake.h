#pragma once

#include <functional>

#include <ctre/phoenix6/CANcoder.hpp>
#include <rev/SparkMax.h>
#include <rev/RelativeEncoder.h>
#include <frc2/command/SubsystemBase.h>
#include <frc/smartdashboard/SmartDashboard.h>


#include "Constants.h"
#include "misc/MaxMotorConfig.h"


class Intake : public frc2::SubsystemBase
{
    public:

        explicit Intake();
        void Periodic();
        void Disable();
        void Deployed();
        void Stowed();
        void IntakeOn();
        void IntakeOff();
        void Stop();

        rev::spark::SparkRelativeEncoder m_intakeEncoder = m_intakeMotor.GetEncoder();
        ctre::phoenix6::hardware::CANcoder m_intakeStateEncoder{ConstantsCanIds::IntakeEncoderId};

        
    private:


        rev::spark::SparkMax m_intakeMotor{ConstantsCanIds::IntakeMotorId, rev::spark::SparkLowLevel::MotorType::kBrushless};
        
        rev::spark::SparkMax m_intakeDeployer{ConstantsCanIds::IntakeDeployerId, rev::spark::SparkLowLevel::MotorType::kBrushless};
        

};