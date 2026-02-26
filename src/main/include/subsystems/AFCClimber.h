#pragma once

#include <string.h>

#include <rev/SparkMax.h>
#include <rev/RelativeEncoder.h>
#include <frc2/command/SubsystemBase.h>
#include <frc/smartdashboard/SmartDashboard.h>

#include "Constants.h"
#include "misc/MaxMotorConfig.h"




class AFCClimber : public frc2::SubsystemBase
{
    public:

        explicit AFCClimber();

        void Periodic() override;
        void Disable();
        void ClimberDown();
        void ClimberUp();
        void SetManualSpeed(double speed);
        void Stop();
    private:

        rev::spark::SparkMax m_climberMotor{ConstantsCanIds::ClimberMotorId,rev::spark::SparkLowLevel::MotorType::kBrushless};
        rev::spark::SparkRelativeEncoder m_climberEncoder = m_climberMotor.GetEncoder();
};