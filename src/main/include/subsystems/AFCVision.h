#pragma once

#include <functional>
#include <cmath>
#include <numbers>

#include <frc2/command/SubsystemBase.h>
#include <frc2/command/CommandPtr.h>
#include <frc2/command/Commands.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/DriverStation.h>

#include "LimelightHelpers.h"
struct Vector2D {
    double x, y;
};

class AFCVision : public frc2::SubsystemBase
{
    public:

        explicit AFCVision();
        void Periodic() override;
        double TurretDistanceCalc(double LLAngleToRad);
        double LLAngleToRad();
        double SpeedRamp(double TurretDistanceCalc);
        double FlySpeed = 0.0;


        // Vector2D GetCurrentTarget();
        // double CalcCompAngle();
        // void TurretFace();
        // void RobotFace();
        // void Disable();
        // void Stop();

    private:
        
        double m_txTurret = 0.0;
        bool turretHasTarget = false;
        
        double m_tyTurret = 0.0;
        bool robotHasTarget = false;

        double x_cord = 0.0;
        double y_cord = 0.0;
        double TgtDistance = 0.0;
        
};