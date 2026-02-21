#pragma once

#pragma region Includes

#include <functional>

#include <rev/SparkMax.h>
#include <frc2/command/SubsystemBase.h>
#include <frc/smartdashboard/SmartDashboard.h>

#include "Constants.h"
#include "misc/MaxMotorConfig.h"
#pragma endregion


class Indexer : public frc2::SubsystemBase{

    public:
            explicit Indexer(); 
            void Periodic() override;
            void Disable();
            void ConveyorOn(double speed = 1.0);
            void ConveyorOff(double speed = 0);
            void UptakeOn(double speed = -1.0);
            void UptakeOff(double speed = 0);
            void Stop();


    private:
        rev::spark::SparkMax m_conveyorMotor{ConstantsCanIds::conveyorMotorID, rev::spark::SparkLowLevel::MotorType::kBrushless};
        rev::spark::SparkMax m_uptakeMotor{ConstantsCanIds::uptakeMotorID, rev::spark::SparkLowLevel::MotorType::kBrushless};

};
