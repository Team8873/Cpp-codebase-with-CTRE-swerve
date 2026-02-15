#pragma once

#pragma region Includes

#include <functional>

#include <rev/SparkMax.h>
#include <frc2/command/SubsystemBase.h>

#include "Constants.h"
#include "misc/MaxMotorConfig.h"
#pragma endregion


#pragma region IndexerConstants
namespace IndexerConstant{
        constexpr double conveyorSpeed = 0.5;
        constexpr double uptakeSpeed = 0.5;

}
#pragma endregion

class Indexer : public frc2::SubsystemBase{

    public:
            explicit Indexer();
            void Periodic() override;
            void Disable();
            void ConveyorOn(double speed = 0.8);
            void ConverorOff(double speed = 0.0);
            void UptakeOn(double speed = 0.5);
            void UptakeOff(double speed = 0.0);
            void Stop(); 
            


        //conveyorState GetConveyorState() const { return m_conveyorState;}
        //uptakeState GetUptakeState() const {  return m_uptakeState;}


    private:
        rev::spark::SparkMax m_conveyorMotor{ConstantsCanIds::conveyorMotorID, rev::spark::SparkLowLevel::MotorType::kBrushless};
        rev::spark::SparkMax m_uptakeMotor{ConstantsCanIds::uptakeMotorID, rev::spark::SparkLowLevel::MotorType::kBrushless};

        //conveyorState m_conveyorState = conveyorState::conveyorOff;
        //uptakeState m_uptakeState = uptakeState::uptakeOff;
};