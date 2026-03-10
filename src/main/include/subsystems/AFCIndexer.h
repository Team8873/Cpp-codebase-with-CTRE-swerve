#pragma once


#include <functional>

#include <rev/SparkMax.h>
#include <frc2/command/SubsystemBase.h>
#include <ctre/phoenix6/TalonFX.hpp>
#include <ctre/phoenix6/CANcoder.hpp>

#include "Constants.h"
#include "misc/MaxMotorConfig.h"
#include "misc/TalonMotorConfig.h"



namespace IndexerConstant{
        constexpr double conveyorSpeed = 0.5;
        constexpr double uptakeSpeed = 0.5;

}


class AFCIndexer : public frc2::SubsystemBase{

    public:
        explicit AFCIndexer();
        void Periodic() override;
        void Disable();
        void ConveyorOn();
        void UptakeReverse();
        void UptakeOn();
         void Stop(); 
            


        

    private:
        ctre::phoenix6::hardware::TalonFX m_uptaker{ConstantsCanIds::uptakerMotorID};
        rev::spark::SparkMax m_conveyorMotor{ConstantsCanIds::ConveyorMotorId, rev::spark::SparkLowLevel::MotorType::kBrushless};
        rev::spark::SparkMax m_uptakeMotor{ConstantsCanIds::UptakeMotorId, rev::spark::SparkLowLevel::MotorType::kBrushless};

        
};