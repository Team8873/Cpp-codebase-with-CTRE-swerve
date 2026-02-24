#pragma once


#include <functional>

#include <rev/SparkMax.h>
#include <frc2/command/SubsystemBase.h>
#include <frc/smartdashboard/SmartDashboard.h>

#include "Constants.h"
#include "misc/MaxMotorConfig.h"


class Indexer : public frc2::SubsystemBase{

    public:
            explicit Indexer(); 
            void Periodic() override;
            void Disable();
            void ConveyorOn();
            void ConveyorOff();
            void UptakeOn(bool argument);
            void UptakeOff();
            void Stop();


    private:
        rev::spark::SparkMax m_conveyorMotor{ConstantsCanIds::conveyorMotorID, rev::spark::SparkLowLevel::MotorType::kBrushless};
        rev::spark::SparkMax m_uptakeMotor{ConstantsCanIds::uptakeMotorID, rev::spark::SparkLowLevel::MotorType::kBrushless};

        bool argument = false;

};
