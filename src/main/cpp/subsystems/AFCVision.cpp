#include "subsystems/AFCVision.h"




AFCVision::AFCVision(){
}

void AFCVision::Periodic(){
    m_txTurret = LimelightHelpers::getTX("");
    m_tyTurret = LimelightHelpers::getTY("");
    turretHasTarget = LimelightHelpers::getTV("");
    TgtDistance = TurretDistanceCalc(LLAngleToRad());
    FlySpeed = SpeedRamp(TgtDistance);
    // robotHasTarget = LimelightHelpers::getTV("");
    x_cord = LimelightHelpers::getBotpose_wpiBlue("").at(0); //supposedly
    y_cord = LimelightHelpers::getBotpose_wpiBlue("").at(1); //supposedly
    
    
    //frc::SmartDashboard::PutNumber("Calc Compensated Angle", CalcCompAngle());
    frc::SmartDashboard::PutNumber("Turret X Position", m_txTurret);
    frc::SmartDashboard::PutNumber("Turret Y Position", m_tyTurret);
    frc::SmartDashboard::PutBoolean("Turret has Target", turretHasTarget);
    // frc::SmartDashboard::PutBoolean("Robot has Target", robotHasTarget);
    frc::SmartDashboard::PutNumber("xcord", x_cord);
    frc::SmartDashboard::PutBoolean("ycord", y_cord);
    frc::SmartDashboard::PutNumber("Distance From Tgt", TgtDistance);
}

double AFCVision::LLAngleToRad (){
        const double LLAngleOffset = 26;
        const double RadConvert = 0.01745;
      return (m_tyTurret + LLAngleOffset) * RadConvert;
}

double AFCVision::TurretDistanceCalc(double LLAngleToRad){
        const double AdjustedTgtHight = 0.5207;
        
        return 0.5207/tan(LLAngleToRad);
}

double AFCVision::SpeedRamp(double TgtDistance){
        return (1.59*(TgtDistance*TgtDistance)) + (1.84 * TgtDistance) + 50.92;
}


// Vector2D GetCurrentTarget(){
//     double txTarget = LimelightHelpers::getTX("");
//     double tyTarget = LimelightHelpers::getTY("");
//     bool turretHasTarget = LimelightHelpers::getTV("");

//     if (!turretHasTarget) return {0, 0};
//     // 45 target hight 4 camera 30 angle of camera
//     double distance = (45.0 - 24.0) / std::tan((30.0 + tyTarget) * (std::numbers::pi / 180.0));

//     double x = distance * std::cos(txTarget * (std::numbers::pi / 180));
//     double y = distance * std::sin(tyTarget * (std::numbers::pi / 180));
//     return {x, y};
// }

// double CalcCompAngle(double robotXVel, double robotYVel){
//     Vector2D targetPos = GetCurrentTarget();
//     if (targetPos.x == 0 && targetPos.y == 0) return 0.0;

//     double distance = std::sqrt(targetPos.x * targetPos.x + targetPos.y * targetPos.y);
//     double FuelAirTime = distance / 350.0;

//     double virtualX = targetPos.x - (robotXVel * FuelAirTime);
//     double virtualY = targetPos.y - (robotYVel * FuelAirTime);

//     double compensatedAngle = std::atan2(virtualY, virtualX) * (180.0 / std::numbers::pi);

//     return compensatedAngle;    
// }

// void AFCVision::TurretFace(){
    
// }

// void AFCVision::Disable(){}

   