// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <pathplanner/lib/auto/AutoBuilder.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/Command.h>
#include <memory>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc2/command/CommandPtr.h>
#include <frc2/command/button/CommandXboxController.h>
#include "subsystems/CommandSwerveDrivetrain.h"
#include "Telemetry.h"
#include "subsystems/Shooter.h"
#include <pathplanner/lib/auto/AutoBuilder.h>

class RobotContainer {
private:
    units::meters_per_second_t MaxSpeed = 1.0 * TunerConstants::kSpeedAt12Volts; // kSpeedAt12Volts desired top speed
    units::radians_per_second_t MaxAngularRate = 0.75_tps; // 3/4 of a rotation per second max angular velocity

    /* Setting up bindings for necessary control of the swerve drive platform */
    swerve::requests::FieldCentric drive = swerve::requests::FieldCentric{}
        .WithDeadband(MaxSpeed * 0.1).WithRotationalDeadband(MaxAngularRate * 0.1) // Add a 10% deadband
        .WithDriveRequestType(swerve::DriveRequestType::OpenLoopVoltage); // Use open-loop control for drive motors
    swerve::requests::SwerveDriveBrake brake{};
    swerve::requests::PointWheelsAt point{};
    swerve::requests::RobotCentric forwardStraight = swerve::requests::RobotCentric{}
        .WithDriveRequestType(swerve::DriveRequestType::OpenLoopVoltage);

    /* Note: This must be constructed before the drivetrain, otherwise we need to
     *       define a destructor to un-register the telemetry from the drivetrain */
    Telemetry logger{MaxSpeed};

    frc2::CommandXboxController joystick{0};

public:
    subsystems::CommandSwerveDrivetrain drivetrain{TunerConstants::CreateDrivetrain()};

private:
    /* Path follower */
    frc::SendableChooser<frc2::Command *> autoChooser;

public:
    RobotContainer();
    Shooter m_Shooter{};

    frc2::Command *GetAutonomousCommand();

private:
    void ConfigureBindings();
};

// using namespace pathplanner;
// // Load the path we want to pathfind to and follow

// auto path = PathPlannerPath::fromPathFile("OverTheRamp.auto");
// // Create the constraints to use while pathfinding. The constraints defined in the path will only be used for the path.
// PathConstraints constraints = PathConstraints(
//     3.0_mps, 4.0_mps_sq,
//     540_deg_per_s, 720_deg_per_s_sq);

// // Since AutoBuilder is configured, we can use it to build pathfinding commands
// frc2::CommandPtr pathfindingCommand = AutoBuilder::pathfindThenFollowPath(
//     path,
//     constraints
// );
