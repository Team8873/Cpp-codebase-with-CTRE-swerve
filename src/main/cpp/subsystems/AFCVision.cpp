#include "subsystems/AFCVision.h"




AFCVision::AFCVision(){
}

void AFCVision::Periodic(){

    LL4HasTarget = LimelightHelpers::getTV("limelight-limenew");
    LL4_X_Cord = nt::NetworkTableInstance::GetDefault().GetTable("limelight-limenew")->GetNumberArray("botpose_orb_wpiblue",std::vector<double>(12)).at(0);
    LL4_Y_Cord = nt::NetworkTableInstance::GetDefault().GetTable("limelight-limenew")->GetNumberArray("botpose_orb_wpiblue",std::vector<double>(12)).at(1);
    LL4_Face_Angle = nt::NetworkTableInstance::GetDefault().GetTable("limelight-limenew")->GetNumberArray("botpose_orb_wpiblue",std::vector<double>(12)).at(5);

    Turret_X_Cord = (std::abs(std::cos(LL4_Face_Angle * (std::numbers::pi / 180.0)))*0.146)+LL4_X_Cord;
    Turret_Y_Cord = (std::sin(LL4_Face_Angle * (std::numbers::pi / 180.0))*0.146)+LL4_Y_Cord;

    X_Range_To_Target = (Target_Cord().at(0)-Turret_X_Cord);
    Y_Range_To_Target = (Target_Cord().at(1)-Turret_Y_Cord);
    Distance_To_Target = (sqrt(std::pow(X_Range_To_Target, 2) + std::pow(Y_Range_To_Target, 2))); 

    Turret_Angle_To_Target = (LL4_Face_Angle-(std::atan2(Y_Range_To_Target, X_Range_To_Target)*(180/std::numbers::pi)));
    SpeedRamp = ((1.59*(Distance_To_Target * Distance_To_Target)) + (1.84 * Distance_To_Target) + 50.92);

    Saved_Turret_Angle = Saved_Turret_Angle_To_Target(LL4HasTarget, Turret_Angle_To_Target);
    Saved_Flywheel_Speed = Saved_Fly_Speed(LL4HasTarget, SpeedRamp);

}

std::array<double,2> Target_Cord()
{
    if (auto ally = frc::DriverStation::GetAlliance()) {
        if (ally.value() == frc::DriverStation::Alliance::kRed) {
            std::array<double,2> RedAllianceHub = {11.915394, 4.034536};
            return RedAllianceHub;
        } else{
        std::array<double,2> BlueAllianceHub = {4.625594 , 4.034536};
            return BlueAllianceHub;
        }
    }
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