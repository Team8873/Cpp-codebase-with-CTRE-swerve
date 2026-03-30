#include "subsystems/AFCVision.h"




AFCVision::AFCVision(){
}

void AFCVision::Periodic(){
    m_txTurret = LimelightHelpers::getTX("limelight-limenew");
    m_tyTurret = LimelightHelpers::getTY("limelight-limenew");
    turretHasTarget = LimelightHelpers::getTV("limelight-limenew");
    robotHasTarget = LimelightHelpers::getTV("limelight-lemold");
    TgtDistance = TurretDistanceCalc(turretllx_cord, turretlly_cord);
    STgtDistance = SavedTargetDistance(turretHasTarget, TgtDistance);
    TgtAngle = RobotAngleCalc(botllx_cord, botlly_cord, botll_faceangle);
    STgtAngle = SavedTargetAngle(robotHasTarget, TgtAngle);
    turretYVelocity = TurretYCalc(ll4YVel);
    FlySpeed = SpeedRamp(STgtDistance);
    compensatedAngle = CalcAjustAngle(ll4XVel, TurretYVel);
    // robotHasTarget = LimelightHelpers::getTV("");
    turretllx_cord = LimelightHelpers::getBotpose_wpiBlue("limelight-limenew").at(0);
    turretlly_cord = LimelightHelpers::getBotpose_wpiBlue("limelight-limenew").at(1);

    botllx_cord = LimelightHelpers::getBotpose_wpiBlue("limelight-lemold").at(0);
    botlly_cord = LimelightHelpers::getBotpose_wpiBlue("limelight-lemold").at(1);
    botll_faceangle = LimelightHelpers::getBotpose_wpiBlue("limelight-lemold").at(5);
    
    ll4XAcell = nt::NetworkTableInstance::GetDefault().GetTable("limelight-limenew")->GetNumberArray("imu",std::vector<double>(10)).at(7);
    ll4YAcell = nt::NetworkTableInstance::GetDefault().GetTable("limelight-limenew")->GetNumberArray("imu",std::vector<double>(10)).at(9);
    //double something = nt::NetworkTableInstance::GetDefault().GetTable("limelight")->GetNumberArray("imu",std::vector<double>(10)).at(0);


    ll4XVel = LimelightXAcceleration(ll4XAcell, ll4XVel);
    ll4YVel = LimelightYAcceleration(ll4YAcell, ll4YVel);

    TurretYVel = TurretYCalc(ll4YVel);

    //frc::SmartDashboard::PutNumber("Calc Compensated Angle", CalcCompAngle());
    frc::SmartDashboard::PutNumber("Turret X Position", m_txTurret);
    frc::SmartDashboard::PutNumber("Turret Y Position", m_tyTurret);
    frc::SmartDashboard::PutBoolean("Turret has Target", turretHasTarget);
    frc::SmartDashboard::PutBoolean("Robot has Target", robotHasTarget);
    frc::SmartDashboard::PutNumber("turret xcord", turretllx_cord);
    frc::SmartDashboard::PutNumber("turret ycord", turretlly_cord);
    frc::SmartDashboard::PutNumber("bot faceangle", botll_faceangle);
    frc::SmartDashboard::PutNumber("Distance From Tgt", TgtDistance);
    frc::SmartDashboard::PutNumber("Fly Speed", FlySpeed);
    frc::SmartDashboard::PutNumber("Saved Target Distance", STgtDistance);

    frc::SmartDashboard::PutNumber("Turret X Velocity", ll4XVel);
    frc::SmartDashboard::PutNumber("Turret Y Velocity", ll4YAcell);
}

 
double AFCVision::TurretDistanceCalc(double x_cord, double y_cord){
       if (auto ally = frc::DriverStation::GetAlliance()) {
    if (ally.value() == frc::DriverStation::Alliance::kRed) {
        return (sqrt(((4.625594-x_cord)*(4.625594-x_cord)+(4.034536-y_cord)*(4.034536-y_cord))));
    } else{
        return (sqrt(((11.915394-x_cord)*(11.915394-x_cord)+(4.034536-y_cord)*(4.034536-y_cord))));
    }
}
}

double AFCVision::RobotAngleCalc(double x_cord, double y_cord, double robot_faceangle){
       if (auto ally = frc::DriverStation::GetAlliance()) {
    if (ally.value() == frc::DriverStation::Alliance::kRed) {
        return ((std::atan2(4.034536-y_cord, 4.625594-x_cord)*(180/std::numbers::pi))-robot_faceangle);
    } else{
        return ((std::atan2(4.034536-y_cord, 11.915394-x_cord)*(180/std::numbers::pi))-robot_faceangle);
    }
}
}

double AFCVision::SpeedRamp(double STgtDistance){
        return (1.59*(STgtDistance * STgtDistance)) + (1.84 * STgtDistance) + 50.92;
}

double AFCVision::CalcAjustAngle(double robotXVel, double robotYVel){
    //Vector2D targetPos = GetCurrentTarget();
    //if (targetPos.x == 0 && targetPos.y == 0) return 0.0;
    //double distance = std::sqrt(targetPos.x * targetPos.x + targetPos.y * targetPos.y);
    double FuelAirTime = STgtDistance / ballFlightSpeed;

    double virtualX = turretllx_cord - (robotXVel * FuelAirTime);
    double virtualY = turretlly_cord - (robotYVel * FuelAirTime);

    return std::atan2(virtualY, virtualX) * (180.0 / std::numbers::pi);    
}

double AFCVision::SavedTargetDistance(bool turretHasTarget, double TgtDistance){
        if (turretHasTarget && TgtDistance < 110){
            return STgtDistance = TgtDistance;
        } else {
            return STgtDistance;
        }
}

double AFCVision::SavedTargetAngle(bool robotHasTarget, double TgtAngle){
        if (robotHasTarget){
            return STgtAngle = TgtAngle;
        } else {
            return STgtAngle;
        }
}

double AFCVision::TurretYCalc(double ll4YVel){
    return turretYVelocity = cos(26)*ll4YVel;
}

double AFCVision::LimelightXAcceleration(double ll4XAccel, double XVelOrigin){

    double XVelocity = ((std::trunc(ll4XAccel*10)/10)+0.4)*0.02+XVelOrigin;

    return XVelOrigin = XVelocity;

}

double AFCVision::LimelightYAcceleration(double ll4YAccel, double YVelOrigin){

    double YVelocity = ((std::trunc(ll4YAccel*10)/10)-0.9)*0.02+YVelOrigin;

    return YVelOrigin = YVelocity;

}

// Vector2D GetCurrentTarget(){
//     double txTarget = LimelightHelpers::getTX("limelight-limenew");
//     double tyTarget = LimelightHelpers::getTY("limelight-limenew");
//     bool turretHasTarget = LimelightHelpers::getTV("limelight-limenew");

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

   