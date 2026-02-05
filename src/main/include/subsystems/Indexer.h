#pragma once

#pragma region Includes

#include <functional>

#include <rev/SparkMax.h>
#include <frc2/command/SubsystemBase.h>

#include "Constants.h"
//#include "misc/MaxMotorConfig.h"
#pragma endregion

class Indexer : public frc2::SubsystemBase{

    public:
            explicit Indexer();
        


    private:
        rev::spark::SparkMax m_conveyorMotor{ConstantsCanIds::ConveyorMotorId, rev::spark::SparkLowLevel::MotorType::kBrushless};
        rev::spark::SparkMax m_uptakeMotor{ConstantsCanIds::UptakeMotorId, rev::spark::SparkLowLevel::MotorType::kBrushless};
};
