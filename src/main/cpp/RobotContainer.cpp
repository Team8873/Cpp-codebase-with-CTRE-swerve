// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"
#include <frc/smartdashboard/SmartDashboard.h>

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
#include <pathplanner/lib/auto/AutoBuilder.h>
#include <pathplanner/lib/commands/PathPlannerAuto.h>
#include <pathplanner/lib/auto/NamedCommands.h>
#include <memory>


#include <pathplanner/lib/auto/NamedCommands.h>

//#include "commands/AFCIndexerComm.h"

using namespace pathplanner;
RobotContainer::RobotContainer() : m_afcIndexer(),m_afcFlywheel(), m_afcIntake(), m_afcShooter(), m_afcKicker()
{
    //NamedCommands::registerCommand("Targeting", std::move(AFCShooter(&m_afcShooter).ToPtr()));
    NamedCommands::registerCommand("Shooting", std::move(AFCShootingComm(&m_afcIndexer, &m_afcFlywheel, &m_afcShooter, &m_afcVision, &m_afcKicker).ToPtr()));
    NamedCommands::registerCommand("Intaking", std::move(AFCIntakeComm(&m_afcIntake, -830.0).ToPtr()));
    NamedCommands::registerCommand("JiggleComm", std::move(AFCJiggleComm(&m_afcIntake).ToPtr())); 
    NamedCommands::registerCommand("PartialIntakeOut", std::move(AFCIntakeComm(&m_afcIntake, -300.0).ToPtr()));   
   
    autoChooser = pathplanner::AutoBuilder::buildAutoChooser("Tests");
    frc::SmartDashboard::PutData("Auto Mode", &autoChooser);
    
    auto state = drivetrain.GetState();
    frc::Pose2d pose = state.Pose;
    frc::ChassisSpeeds speed = state.Speeds;
    frc::SmartDashboard::PutNumber("Bot X Speed", speed.vx.value());
    frc::SmartDashboard::PutNumber("Bot Y Speed", speed.vy.value());
    ConfigureBindings();
     

}



void RobotContainer::ConfigureBindings()
{
    // Note that X is defined as forward according to WPILib convention,
    // and Y is defined as to the left according to WPILib convention.
    drivetrain.SetDefaultCommand(
        // Drivetrain will execute this command periodically
        drivetrain.ApplyRequest([this]() -> auto&& {

        // if (DriverButton.GetLeftBumper()) {
        //     MaxSpeed = 1.5_mps;
        // }

        // else if (DriverButton.GetRightTriggerAxis()) {
        //     MaxSpeed = 4.68_mps;
        // }

        // else {
        //     MaxSpeed = 2.75_mps;
        // }

            return drive.WithVelocityX(-joystick.GetLeftY() * MaxSpeed) // Drive forward with negative Y (forward)
                .WithVelocityY(-joystick.GetLeftX() * MaxSpeed) // Drive left with negative X (left)
                .WithRotationalRate(-joystick.GetRightX() * MaxAngularRate); // Drive counterclockwise with negative X (left)
        })
    );
    
    

    // Idle while the robot is disabled. This ensures the configured
    // neutral mode is applied to the drive motors while disabled.
    frc2::RobotModeTriggers::Disabled().WhileTrue(
        drivetrain.ApplyRequest([] {
            return swerve::requests::Idle{};
        }).IgnoringDisable(true)
    );

    joystick.A().WhileTrue(drivetrain.ApplyRequest([this]() -> auto&& { return brake; }));
    joystick.B().WhileTrue(drivetrain.ApplyRequest([this]() -> auto&& {
        return point.WithModuleDirection(frc::Rotation2d{-joystick.GetLeftY(), -joystick.GetLeftX()});
    }));

    joystick.POVUp().WhileTrue(
        drivetrain.ApplyRequest([this]() -> auto&& {
            return forwardStraight.WithVelocityX(0.5_mps).WithVelocityY(0_mps);
        })
    );
    joystick.POVDown().WhileTrue(
        drivetrain.ApplyRequest([this]() -> auto&& {
            return forwardStraight.WithVelocityX(-0.5_mps).WithVelocityY(0_mps);
        })
    );
    
    joystick.POVRight().WhileTrue(
        drivetrain.ApplyRequest([this]() -> auto&& {
            return forwardStraight.WithVelocityX(0_mps).WithVelocityY(0.5_mps);
        })
    );
    joystick.POVLeft().WhileTrue(
        drivetrain.ApplyRequest([this]() -> auto&& {
            return forwardStraight.WithVelocityX(0_mps).WithVelocityY(-0.5_mps);
        })
    );

    // Run SysId routines when holding back/start and X/Y.
    // Note that each routine should be run exactly once in a single log.
    (joystick.Back() && joystick.Y()).WhileTrue(drivetrain.SysIdDynamic(frc2::sysid::Direction::kForward));
    (joystick.Back() && joystick.X()).WhileTrue(drivetrain.SysIdDynamic(frc2::sysid::Direction::kReverse));
    (joystick.Start() && joystick.Y()).WhileTrue(drivetrain.SysIdQuasistatic(frc2::sysid::Direction::kForward));
    (joystick.Start() && joystick.X()).WhileTrue(drivetrain.SysIdQuasistatic(frc2::sysid::Direction::kReverse));

    // reset the field-centric heading on left bumper press
    joystick.LeftStick().OnTrue(drivetrain.RunOnce([this] { drivetrain.SeedFieldCentric(); }));

    drivetrain.RegisterTelemetry([this](auto const &state) { logger.Telemeterize(state); });

        joystick.LeftBumper().WhileTrue(drivetrain.ApplyRequest([this]() -> auto&& {
            return drive.WithVelocityX(-joystick.GetLeftY() * 1.0_mps) // Drive forward with negative Y (forward)
                .WithVelocityY(-joystick.GetLeftX() * 1.0_mps) // Drive left with negative X (left)
                .WithRotationalRate(-joystick.GetRightX() * 0.45_tps); // Drive counterclockwise with negative X (left)
        }));

        joystick.RightTrigger().WhileTrue(drivetrain.ApplyRequest([this]() -> auto&& {
            return drive.WithVelocityX(-joystick.GetLeftY() * 4.68_mps) // Drive forward with negative Y (forward)
                .WithVelocityY(-joystick.GetLeftX() * 4.68_mps) // Drive left with negative X (left)
                .WithRotationalRate(-joystick.GetRightX() * MaxAngularRate); // Drive counterclockwise with negative X (left)
        }));




    //♦♦♦♦♦♦Start of Operator controls reorganize later♦♦♦♦♦♦

    

    //Indexer controls
    m_afcIndexer.SetDefaultCommand(frc2::cmd::Run([this]{m_afcIndexer.Stop();},{&m_afcIndexer}));
    m_operator.RightTrigger().WhileTrue(frc2::cmd::Run([this]{m_afcIndexer.UptakeOn();},{&m_afcIndexer}));
    

    // m_operator.RightTrigger().WhileTrue(frc2::cmd::Sequence(frc2::cmd::Run([this] {m_afcIndexer.UptakeReverse();}, {&m_afcIndexer}),
    //                                                         frc2::cmd::Run([this] {m_afcIndexer.UptakeOn();}, {&m_afcIndexer})));


    m_operator.RightBumper().WhileTrue(frc2::cmd::Run([this]{m_afcIndexer.UptakeReverse();},{&m_afcIndexer}));

    //Kicker
    m_afcKicker.SetDefaultCommand(frc2::cmd::Run([this]{m_afcKicker.Stop();},{&m_afcKicker}));
     m_operator.RightTrigger().WhileTrue(frc2::cmd::RunOnce([this]{m_afcKicker.KickerOn();},{&m_afcKicker}).AndThen(frc2::cmd::Wait(0.3_s)) 
                            .AndThen(frc2::cmd::RunOnce([this]{m_afcKicker.Stop();},{&m_afcKicker})).AndThen(frc2::cmd::Wait(0.5_s)).Repeatedly());
    // m_operator.RightTrigger().WhileTrue(frc2::cmd::Run([this]{m_afcKicker.KickerJitter();},{&m_afcKicker}));
    m_operator.RightBumper().WhileTrue(frc2::cmd::Run([this]{m_afcKicker.KickerBack();},{&m_afcKicker}));

    //Intake controls
<<<<<<< HEAD
    m_afcIntake.SetDefaultCommand(frc2::cmd::Run([this]{m_afcIntake.DeploySpeed(-m_operator.GetLeftY());},{&m_afcIntake}));
    m_operator.LeftBumper().WhileTrue(frc2::cmd::Run([this]{m_afcIntake.IntakeSpeed(1);},{&m_afcIntake})); //Be aware this is a built in negative on variable in the subsytem file
=======
    m_afcIntake.SetDefaultCommand(frc2::cmd::Run([this]{m_afcIntake.DeploySpeed(-m_operator.GetRightY());},{&m_afcIntake}));
    m_operator.LeftBumper().WhileTrue(frc2::cmd::Run([this]{m_afcIntake.IntakeSpeed(0.5);},{&m_afcIntake})); //Be aware this is a built in negative on variable in the subsytem file
>>>>>>> Secon_Rule_Of_FightClub
    m_operator.LeftBumper().MultiPress(2, 250_ms).WhileTrue(frc2::cmd::Run([this]{m_afcIntake.IntakeSpeed(0);},{&m_afcIntake}));
    m_operator.B().WhileTrue(frc2::cmd::Run([this]{m_afcIntake.JigglePhysics();},{&m_afcIntake}));
    m_operator.LeftStick().WhileTrue(frc2::cmd::Run([this]{m_afcIntake.Deployer(-830.0);},{&m_afcIntake}));

   //Outake Controls
    m_operator.Button(7).WhileTrue(frc2::cmd::Run([this]{m_afcIntake.IntakeSpeed(-0.5);},{&m_afcIntake})); //Be aware this is a built in negative on variable in the subsytem file
    m_operator.Button(7).MultiPress(2, 250_ms).WhileTrue(frc2::cmd::Run([this]{m_afcIntake.IntakeSpeed(0);},{&m_afcIntake})); //Be aware this is a built in negative on variable in the subsytem file
    
    //Turret Turn
    m_afcShooter.SetDefaultCommand(frc2::cmd::Run([this]{m_afcShooter.TurretSpeed(0);},{&m_afcShooter}));
    m_operator.POVLeft().WhileTrue(frc2::cmd::Run([this]{m_afcShooter.TurretSpeed(0.1);},{&m_afcShooter}));
    m_operator.POVRight().WhileTrue(frc2::cmd::Run([this]{m_afcShooter.TurretSpeed(-0.1);},{&m_afcShooter}));
    m_operator.X().WhileTrue(frc2::cmd::Run([this]{m_afcShooter.TurretPOS(0);},{&m_afcShooter}));
    m_operator.Y().WhileTrue(frc2::cmd::Run([this]{m_afcShooter.TurretPOS(-200);},{&m_afcShooter}));
    m_operator.A().WhileTrue(frc2::cmd::Run([this]{m_afcShooter.TurretPOS(200);},{&m_afcShooter}));

    //Auto Lock
<<<<<<< HEAD
    // m_afcFlywheel.SetDefaultCommand(frc2::cmd::Run([this]{m_afcFlywheel.Idle();},{&m_afcFlywheel}));
=======
>>>>>>> Secon_Rule_Of_FightClub
    m_operator.LeftTrigger().WhileTrue(frc2::cmd::Run([this]{m_afcShooter.TurretPOS(m_afcVision.Saved_Turret_Angle);},{&m_afcShooter}));
    m_operator.LeftTrigger().WhileTrue(frc2::cmd::Run([this]{m_afcFlywheel.AutoSpeed(m_afcVision.Saved_Flywheel_Speed);}, {&m_afcVision}));
    //m_operator.LeftTrigger().WhileTrue(frc2::cmd::Run([this]{m_afcShooter.}));

    //Flywheel controls
    //m_operator.B().WhileTrue(frc2::cmd::Run([this]{m_afcFlywheel.SpinUp(0.8);}, {&m_afcFlywheel}));
    //m_operator.B().WhileTrue(frc2::cmd::Run([this]{m_afcFlywheel.ManualSpeed(m_operator.GetLeftY());}, {&m_afcFlywheel}));

    // *
    // *
    // * 
    // * 

    // REMOVE FOR COMP
    m_operator.Start().ToggleOnTrue(frc2::cmd::Run([this]{m_afcFlywheel.Disable();}, {&m_afcFlywheel}));
    // REMOVE FOR COMP
    
    // *
    // *
    // * 
    // * 

    auto state = drivetrain.GetState();
    frc::Pose2d pose = state.Pose;
    frc::ChassisSpeeds speed = state.Speeds;
    double vx = speed.vx.value();
    frc::SmartDashboard::PutNumber("Bot X Speed", vx);
    frc::SmartDashboard::PutNumber("Bot Y Speed", speed.vy.value());
     
}


frc2::Command *RobotContainer::GetAutonomousCommand()
{
    return autoChooser.GetSelected();
}
