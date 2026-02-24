#pragma once

#include <functional>

#include <frc2/command/SubsystemBase.h>
#include <frc2/command/CommandPtr.h>
#include <frc2/command/Commands.h>
#include <frc/smartdashboard/SmartDashboard.h>

#include "LimelightHelpers.h"

class AFCVision : frc2::SubsystemBase
{
    public:

        explicit AFCVision();
        void Periodic() override;
        double turretFaceCalc();
        void TurretFace();
        void RobotFace();
        void Disable();
        void Stop();

    private:

        double m_txTurret = 0.0;
        bool turretHasTarget = false;
        
        double m_txRobot = 0.0;
        bool robotHasTarget = false;
};