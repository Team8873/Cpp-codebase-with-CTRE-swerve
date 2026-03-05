#include "subsystems/AFCVision.h"




AFCVision::AFCVision(){

    //LimelightHelpers::SetFiducialIDFiltersOverride("2", "3","4", "5", "8", "9", "10", "11", "18", "19", "20", "21", "24", "25", "26");
}

void AFCVision::Periodic(){
    m_txTurret = LimelightHelpers::getTX("");
    m_txRobot = LimelightHelpers::getTX("");
    turretHasTarget = LimelightHelpers::getTV("");
    robotHasTarget = LimelightHelpers::getTV("");
    
    
    //frc::SmartDashboard::PutNumber("Calc Compensated Angle", CalcCompAngle());
    frc::SmartDashboard::PutNumber("Turret X Position", m_txTurret);
    frc::SmartDashboard::PutBoolean("Turret has Target", turretHasTarget);
    frc::SmartDashboard::PutBoolean("Robot has Target", robotHasTarget);
    frc::SmartDashboard::PutNumber("Robot X Position", m_txRobot);
}

double turretFaceCalc(double m_txTurret){
        const double kP = 0.02;
        
        return m_txTurret * kP;
}
Vector2D GetCurrentTarget(){
    double txTarget = LimelightHelpers::getTX("");
    double tyTarget = LimelightHelpers::getTY("");
    bool turretHasTarget = LimelightHelpers::getTV("");

    if (!turretHasTarget) return {0, 0};
    // 45 target hight 4 camera 30 angle of camera
    double distance = (45.0 - 24.0) / std::tan((30.0 + tyTarget) * (std::numbers::pi / 180.0));

    double x = distance * std::cos(txTarget * (std::numbers::pi / 180));
    double y = distance * std::sin(tyTarget * (std::numbers::pi / 180));
    return {x, y};
}

double CalcCompAngle(double robotXVel, double robotYVel){
    Vector2D targetPos = GetCurrentTarget();
    if (targetPos.x == 0 && targetPos.y == 0) return 0.0;

    double distance = std::sqrt(targetPos.x * targetPos.x + targetPos.y * targetPos.y);
    double timeOfFlight = distance / 350.0;

    double virtualX = targetPos.x - (robotXVel * timeOfFlight);
    double virtualY = targetPos.y - (robotYVel * timeOfFlight);

    double compensatedAngle = std::atan2(virtualY, virtualX) * (180.0 / std::numbers::pi);

    return compensatedAngle;    
}

void AFCVision::TurretFace(){
    
}

void AFCVision::Disable(){}

   