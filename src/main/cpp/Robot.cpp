// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"
#include "LimelightHelpers.h"
#include <frc2/command/CommandScheduler.h>
#include <cameraserver/CameraServer.h>

Robot::Robot() {}

void Robot::RobotPeriodic() {
    m_timeAndJoystickReplay.Update();
    frc2::CommandScheduler::GetInstance().Run();

   
    // /*This example of adding Limelight is very simple and may not be sufficient for on-field use.
    //  * Users typically need to provide a standa
    //  * rd deviation that scales with the distance to target
    //  * and changes with number of tags available.
    //  *
    //  * This example is sufficient to show that vision integration is possible, though exact implementation
    //  * of how to use vision should be tuned per-robot and to the team's specification.
    //  */
    // if (kUseLimelight) {
    //     auto const driveState = m_container.drivetrain.GetState();
    //     auto const heading = driveState.Pose.Rotation().Degrees();
    //     auto const omega = driveState.Speeds.omega;

    //     LimelightHelpers::SetRobotOrientation("limelight-lemold", heading.value(), 0, 0, 0, 0, 0);
    //     auto llMeasurement = LimelightHelpers::getBotPoseEstimate_wpiBlue_MegaTag2("limelight-lemold");
    //     if (llMeasurement && llMeasurement->tagCount > 0 && units::math::abs(omega) < 2_tps) {
    //         m_container.drivetrain.AddVisionMeasurement(llMeasurement->pose, llMeasurement->timestampSeconds);
    //     }
    // }
}

void Robot::DisabledInit() {
    frc::CameraServer::StartAutomaticCapture();
}

void Robot::DisabledPeriodic() {
   //  RobotAngle = nt::NetworkTableInstance::GetDefault().GetTable("limelight-limenew")->GetNumberArray("botpose_orb_wpiblue",std::vector<double>(12)).at(5);
    
   // LimelightHelpers::SetRobotOrientation("limelight-limenew", RobotAngle, 0, 0, 0, 0, 0);
LimelightHelpers::SetIMUAssistAlpha("limelight-limenew", 1),
    LimelightHelpers::SetIMUMode("limelight-limenew", 3);
}
void Robot::DisabledExit() {}

void Robot::AutonomousInit() {

   // m_afcIntake.SetDefaultCommand(frc2::cmd::Run([this]{m_afcIntake.IntakeSpeed(0);},{&m_afcIntake}));
    m_autonomousCommand = m_container.GetAutonomousCommand();

    if (m_autonomousCommand) {
        frc2::CommandScheduler::GetInstance().Schedule(m_autonomousCommand);
    }
}

void Robot::AutonomousPeriodic() {
    LimelightHelpers::SetIMUAssistAlpha("limelight-limenew", 1),
    LimelightHelpers::SetIMUMode("limelight-limenew", 3);
}

void Robot::AutonomousExit() {}

void Robot::TeleopInit() {
    LimelightHelpers::SetIMUAssistAlpha("limelight-limenew", 1),
    LimelightHelpers::SetIMUMode("limelight-limenew", 3);
    if (m_autonomousCommand) {
        frc2::CommandScheduler::GetInstance().Cancel(m_autonomousCommand);
    }
}

void Robot::TeleopPeriodic() {
LimelightHelpers::SetIMUAssistAlpha("limelight-limenew", 1),
LimelightHelpers::SetIMUMode("limelight-limenew", 3);
}

void Robot::TeleopExit() {}

void Robot::TestInit() {
    frc2::CommandScheduler::GetInstance().CancelAll();
}

void Robot::TestPeriodic() {}

void Robot::TestExit() {}

#ifndef RUNNING_FRC_TESTS
int main() {
    return frc::StartRobot<Robot>();
}
#endif
