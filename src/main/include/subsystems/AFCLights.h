#pragma once

#include <ctre/phoenix6/CANdle.hpp>

#include <frc2/command/SubsystemBase.h>
#include <frc2/command/Commands.h>
#include <frc2/command/CommandPtr.h>
#include <frc/smartdashboard/SmartDashboard.h>

#include "LimelightHelpers.h"
#include "Constants.h"

class AFCLights : public frc2::SubsystemBase
{
    public:

        explicit AFCLights();
        void Periodic() override;
        void Disable();
        void Stop();

    private:

        ctre::phoenix6::hardware::CANdle m_candle{ConstantsCanIds::CANdleId};

};


