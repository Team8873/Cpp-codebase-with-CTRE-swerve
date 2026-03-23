#pragma once

#include <functional>
#include <cmath>
#include <numbers>
#include <vector>
#include <algorithm>

#include <frc2/command/SubsystemBase.h>
#include <frc2/command/CommandPtr.h>
#include <frc2/command/Commands.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/DriverStation.h>
#include <units/angular_velocity.h>
//#include <frc/smartdashboard/

#include "LimelightHelpers.h"
// struct Vector2D {
//     double x, y;
// };
//std::shared_ptr<NetworkTable> table = nt::NetworkTableInstance::GetDefault().GetTable("limelight");   
// stuct ShootingPoint {

// }

class AFCVision : public frc2::SubsystemBase
{
    public:

        explicit AFCVision();
        void Periodic() override;
        double TurretDistanceCalc(double x_cord, double y_cord);
        //double LLAngleToRad();
        double SpeedRamp(double TurretDistanceCalc);
        double FlySpeed = 0.0;
        // Vector2D GetCurrentTarget();
        double CalcCompAngle(double robotXVel, double robotYVel);
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

        double targetHeight = 45.0;
        double cameraHeight = 24.0;
        double cameraAngle = 30.0;
        double ballFlightSpeed = 240.0; // Muzzle velocity of Fuel in inches
        double compensatedAngle = 0.0;
        double ll4XVel = 0.0;
        double ll4YVel = 0.0;
        
};