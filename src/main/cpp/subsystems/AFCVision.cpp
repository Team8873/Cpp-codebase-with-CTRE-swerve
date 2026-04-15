#include "subsystems/AFCVision.h"




AFCVision::AFCVision(){
    auto inst = nt::NetworkTableInstance::GetDefault();
    auto table = inst.GetTable("DriveState");
}

void AFCVision::Periodic(){
    
    
    
    LL4HasTarget = LimelightHelpers::getTV("limelight-limenew");
    LL4_X_Cord = nt::NetworkTableInstance::GetDefault().GetTable("limelight-limenew")->GetNumberArray("botpose_orb_wpiblue",std::vector<double>(12)).at(0);
    LL4_Y_Cord = nt::NetworkTableInstance::GetDefault().GetTable("limelight-limenew")->GetNumberArray("botpose_orb_wpiblue",std::vector<double>(12)).at(1);
    LL4_Face_Angle = nt::NetworkTableInstance::GetDefault().GetTable("limelight-limenew")->GetNumberArray("botpose_orb_wpiblue",std::vector<double>(12)).at(5);

    Turret_X_Cord = (std::abs(std::cos(LL4_Face_Angle * (std::numbers::pi / 180.0)))*0.146)+LL4_X_Cord;
    Turret_Y_Cord = (std::sin(LL4_Face_Angle * (std::numbers::pi / 180.0))*0.146)+LL4_Y_Cord;

    X_Range_To_Target = (Target_Cord().x-Turret_X_Cord);
    Y_Range_To_Target = (Target_Cord().y-Turret_Y_Cord);
    Distance_To_Target = (sqrt(std::pow(X_Range_To_Target, 2) + std::pow(Y_Range_To_Target, 2))); 

    Turret_Angle_To_Target = (LL4_Face_Angle-(std::atan2(Y_Range_To_Target, X_Range_To_Target)*(180/std::numbers::pi)));
    SpeedRamp = ((0.673559*(Distance_To_Target * Distance_To_Target)) + (7.52202 * Distance_To_Target) + 37.9335);

    Saved_Turret_Angle = Saved_Turret_Angle_To_Target(LL4HasTarget, Turret_Angle_To_Target);
    Saved_Flywheel_Speed = Saved_Fly_Speed(LL4HasTarget, SpeedRamp);

    
 double vx = vxSub.Get();
 
    double netvx = frc::SmartDashboard::GetNumber("vx", 0.0);
    double netvy = frc::SmartDashboard::GetNumber("vy", 0.0);
    units::meter_t X_Speed = units::meter_t{netvx};
    units::meter_t Y_Speed = units::meter_t{netvy};
    units::meter_t X_Range = units::meter_t{X_Range_To_Target};
    units::meter_t Y_Range = units::meter_t{Y_Range_To_Target};
    frc::Translation2d targetPosistion{X_Range, Y_Range};
    frc::Translation2d targetVector = ((targetPosistion / Distance_To_Target) * SpeedRamp);
    frc::Translation2d robotVelocity{X_Speed, Y_Speed};
    frc::Translation2d shotVector = (targetVector - robotVelocity);
    double Something = shotVector.Angle().Degrees().value();

    
    frc::SmartDashboard::PutNumber("Nothing", Something);
    frc::SmartDashboard::PutNumber("Angle to Target", Turret_Angle_To_Target);
    frc::SmartDashboard::PutNumber("Something X", vx);
    frc::SmartDashboard::PutNumber("Somthing Y", netvy);
}

Vector2D AFCVision::Target_Cord(){
    if (auto ally = frc::DriverStation::GetAlliance()) {
        if (ally.value() == frc::DriverStation::Alliance::kRed) {
            return {11.915394, 4.034536};
        } else{
            return {4.625594, 4.034536};
        }
    }
}
double AFCVision::Shoot_Scoot(double Robot_X_Vel, double Robot_Y_Vel){
    Vector2D Tar_Pos = Target_Cord();
    Fuel_Air_Time = Distance_To_Target / ballFlightSpeed;
    double virtualX = Tar_Pos.x - (Robot_X_Vel * Fuel_Air_Time);
    double virtualY = Tar_Pos.y - (Robot_Y_Vel * Fuel_Air_Time);
    return 0;

}
double AFCVision::Saved_Turret_Angle_To_Target(bool Robot_Has_Target, double Angle_To_Target){
        if (Robot_Has_Target && Angle_To_Target < 110){
            return Saved_Turret_Angle = Angle_To_Target;
        } else {
            return Saved_Turret_Angle;
        }
}

double AFCVision::Saved_Fly_Speed(bool Robot_Has_Target, double Target_Distance){
        if (Robot_Has_Target && Target_Distance < 110){
            return Saved_Flywheel_Speed = Target_Distance;
        } else {
            return Saved_Flywheel_Speed;
        }
}