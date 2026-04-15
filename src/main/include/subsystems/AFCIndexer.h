#pragma once


#include <functional>

#include <rev/SparkMax.h>
#include <TimeOfFlight.h>
#include <frc2/command/SubsystemBase.h>
#include <ctre/phoenix6/TalonFX.hpp>

#include "Constants.h"
#include "misc/MaxMotorConfig.h"
#include "misc/TalonMotorConfig.h"

#include <chrono>




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
        bool HopperEmpty();
        double GetDis();
        double Convert();
        void Stop(); 
            


        

    private:
        ctre::phoenix6::hardware::TalonFX m_uptaker{ConstantsCanIds::UptakerMotorID};
        rev::spark::SparkMax m_conveyorMotor{ConstantsCanIds::ConveyorMotorId, rev::spark::SparkLowLevel::MotorType::kBrushless};
        rev::spark::SparkMax m_uptakeMotor{ConstantsCanIds::UptakeMotorId, rev::spark::SparkLowLevel::MotorType::kBrushless};
        pwf::TimeOfFlight m_distanceSensor{1};
        double distanceInmm = 0.0;
        double distanceInInches = 0.0;
        const double mmToInches = 25.4;
        
};