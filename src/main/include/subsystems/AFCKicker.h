#pragma once


#include <functional>
#include <chrono>

#include <rev/SparkMax.h>
#include <TimeOfFlight.h>
#include <frc2/command/SubsystemBase.h>
#include <ctre/phoenix6/TalonFX.hpp>

#include "Constants.h"
#include "misc/MaxMotorConfig.h"
#include "misc/TalonMotorConfig.h"
#include "frc2/command/Commands.h"


class AFCKicker : public frc2::SubsystemBase{
    public:
            explicit AFCKicker();
            void KickerOn();
            void KickerBack();
            void KickerJitter();
            void Stop();
    private:
        rev::spark::SparkMax m_kickerBarMotor{ConstantsCanIds::KickerBarMotorId, rev::spark::SparkLowLevel::MotorType::kBrushless};
        rev::spark::SparkRelativeEncoder m_kickerBarEncoder = m_kickerBarMotor.GetEncoder();
};