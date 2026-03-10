#pragma once



#include <functional>
#include <vector>
#include <algorithm>

#include <ctre/phoenix6/TalonFX.hpp>
#include <ctre/phoenix6/CANcoder.hpp>

#include <rev/SparkMax.h>
#include <rev/RelativeEncoder.h>

#include <frc2/command/SubsystemBase.h>
#include <frc2/command/CommandPtr.h>
#include <frc/Servo.h>
#include <frc2/command/Commands.h>
#include <frc/smartdashboard/SmartDashboard.h>
//#include <frc/controller/PIDController.h>

#include "LimelightHelpers.h"

#include "Constants.h"
#include "misc/MaxMotorConfig.h"
#include "misc/TalonMotorConfig.h"

struct ShootingPoint {
    double distance;
    double rpm;
    double hoodAngle;
    //units::turns_per_second rpm;

};
std::vector<ShootingPoint> shooterLUT = {
    {60.0, 20.0, 25.0},//75_tps},  5 feet 
};
// std::vector<ShootingPoint> shooterLUT = {
//     {}
// };
class AFCShooter : public frc2::SubsystemBase
{
    public:

        explicit AFCShooter();
        void Periodic() override;
        void TurretPOS(double pos);
        void TurretDirectionInput(double othernumber);
        void TurretSpeed(double speed);
        void AutoLock(double TX);
        double GetPosition();
        void Disable();
        void Stop();

    private:
        
        rev::spark::SparkMax m_turretMotor{ConstantsCanIds::TurretMotorId, rev::spark::SparkLowLevel::MotorType::kBrushless};
        rev::spark::SparkRelativeEncoder m_turretEncoder = m_turretMotor.GetEncoder();
        frc::Servo m_hoodServos{1};

        double m_tx = 0.0;
        double txNeed = 100.0;
        bool hasTarget = false;
        double turPos = 0.0;
        double velocity = 0.0;
        


};

