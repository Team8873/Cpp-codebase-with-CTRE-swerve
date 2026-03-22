#include "subsystems/AFCVision.h"




AFCVision::AFCVision(){
}

void AFCVision::Periodic(){
    m_txTurret = LimelightHelpers::getTX("");
    m_tyTurret = LimelightHelpers::getTY("");
    turretHasTarget = LimelightHelpers::getTV("");
    TgtDistance = TurretDistanceCalc(x_cord, y_cord);
    FlySpeed = SpeedRamp(TgtDistance);
    x_cord = LimelightHelpers::getBotpose_wpiBlue("").at(0); //supposedly
    y_cord = LimelightHelpers::getBotpose_wpiBlue("").at(1); //supposedly
    //ll4XVel = LimelightHelpers::SetIMU
    //compensatedAngle;
    //nt::
    //auto vel = LimelightHelpers::getCameraPose_RobotSpace("");
    
    frc::SmartDashboard::PutNumber("Turret X Position", m_txTurret);
    frc::SmartDashboard::PutNumber("Turret Y Position", m_tyTurret);
    frc::SmartDashboard::PutBoolean("Turret has Target", turretHasTarget);
    frc::SmartDashboard::PutNumber("xcord", x_cord);
    frc::SmartDashboard::PutBoolean("ycord", y_cord);
    frc::SmartDashboard::PutNumber("Distance From Tgt", TgtDistance);
}

double AFCVision::LLAngleToRad (){
        const double LLAngleOffset = 26;
        const double RadConvert = 0.01745;
      return (m_tyTurret + LLAngleOffset) * RadConvert;
}

double AFCVision::TurretDistanceCalc(double x_cord, double y_cord){
        if (auto ally = frc::DriverStation::GetAlliance()){
                if (ally.value() == frc::DriverStation::Alliance::kRed){
                        return (sqrt(((4.625594-x_cord)*(4.625594-x_cord)+(4.034536-y_cord)*(4.034536-y_cord))));
                }
                else{
                        return (sqrt(((11.915394-x_cord)*(11.915394-x_cord)+(4.034536-y_cord)*(4.034536-y_cord))));
                }

        }
}

double AFCVision::SpeedRamp(double TgtDistance){
        return (1.59*(TgtDistance*TgtDistance)) + (1.84 * TgtDistance) + 50.92;
}


// Vector2D AFCVision::GetCurrentTarget(){
// //     double txTarget = LimelightHelpers::getTX("");
// //     double tyTarget = LimelightHelpers::getTY("");
// //     bool turretHasTarget = LimelightHelpers::getTV("");

//     if (!turretHasTarget) return {0, 0};
//     // 45 target hight 24 camera 30 angle of camera
//     double distance = (targetHeight - cameraHeight) / std::tan((cameraAngle + m_tyTurret) * (std::numbers::pi / 180.0));

//     double x = distance * std::cos(m_txTurret * (std::numbers::pi / 180));
//     double y = distance * std::sin(m_tyTurret * (std::numbers::pi / 180));
//     return {x, y};
// }

double AFCVision::CalcCompAngle(double robotXVel, double robotYVel){
    //Vector2D targetPos = GetCurrentTarget();
    //if (targetPos.x == 0 && targetPos.y == 0) return 0.0;
    //double distance = std::sqrt(targetPos.x * targetPos.x + targetPos.y * targetPos.y);
    double FuelAirTime = TgtDistance / ballFlightSpeed;

    double virtualX = x_cord - (robotXVel * FuelAirTime);
    double virtualY = y_cord - (robotYVel * FuelAirTime);

    return std::atan2(virtualY, virtualX) * (180.0 / std::numbers::pi);    
}

// void AFCVision::TurretFace(){
    
// }

// void AFCVision::Disable(){}

   