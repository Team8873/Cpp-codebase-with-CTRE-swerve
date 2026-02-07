#pragma once

#pragma region Includes

#include <functional>

#include <rev/SparkMax.h>
#include <frc2/command/SubsystemBase.h>

#include "Constants.h"
#include "misc/MaxMotorConfig.h"
#pragma endregion

#pragma region IndexerEnums

enum IndexerState{
        conveyorOn,
        uptakeOn,
        syncOn,
        conveyorOff,
        uptakeOff,
        syncOff
};

#pragma endregion 

#pragma region IndexerConstants
namespace IndexerConstant{
        //FIX ME (declaration not actually values)
        constexpr auto conveyorSpeed = 0;
        constexpr auto uptakeSpeed = 0;

        constexpr auto conveyorSpeed = 0;
        constexpr auto uptakeSpeed = 0;
}
#pragma endregion

class Indexer : public frc2::SubsystemBase{

    public:
            explicit Indexer(); 
            void SetState(IndexerState newState);


        IndexerState GetState() const { return m_IndexerState;}


    private:
        rev::spark::SparkMax m_conveyorMotor{ConstantsCanIds::conveyorMotorID, rev::spark::SparkLowLevel::MotorType::kBrushless};
        rev::spark::SparkMax m_uptakeMotor{ConstantsCanIds::uptakeMotorID, rev::spark::SparkLowLevel::MotorType::kBrushless};

        IndexerState m_IndexerState = IndexerState::syncOff;
};
