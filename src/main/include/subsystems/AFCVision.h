#pragma once

#include <functional>
#include <cmath>
#include <numbers>
#include <vector>
#include <array>
#include <algorithm>
#include <iostream>

#include <frc2/command/SubsystemBase.h>
#include <frc2/command/CommandPtr.h>
#include <frc2/command/Commands.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/kinematics/ChassisSpeeds.h>
#include <frc/DriverStation.h>
#include <units/angular_velocity.h>

#include "LimelightHelpers.h"

struct Vector2D {
    double x, y;
};

class AFCVision : public frc2::SubsystemBase
{
    public:

    explicit AFCVision();
    void Periodic() override;
    Vector2D Target_Cord();
    double Saved_Turret_Angle_To_Target(bool Robot_Has_Target, double Angle_To_Target);
    double Saved_Fly_Speed(bool Robot_Has_Target, double Target_Distance);

    double Saved_Turret_Angle = 0.0;
    double Saved_Flywheel_Speed = 0.0;
    


    private:

       bool LL4HasTarget = false;    //
       double LL4_X_Cord = 0.0;      // Data From LL4
       double LL4_Y_Cord = 0.0;      //
       double LL4_Face_Angle = 0.0;  //

       double Turret_X_Cord = 0.0;
       double Turret_Y_Cord = 0.0;

       double X_Range_To_Target = 0.0;
       double Y_Range_To_Target = 0.0;
       double Distance_To_Target = 0.0;
       double Turret_Angle_To_Target = 0.0;

       double SpeedRamp = 0.0;

//---------------------------------- Shoot & Scoot ---------------------------------
       double ballFlightSpeed = 240.0; // Muzzle velocity of Fuel in inches

       double LL4_X_Acell = 0.0;
       double LL4_Y_Acell = 0.0;
       double LL4_X_Vel = 0.0;
       double LL4_Y_Vel = 0.0;
       double TurretYVel = 0.0;


};