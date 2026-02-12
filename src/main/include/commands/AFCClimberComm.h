#pragma once

#pragma region Includes
#include <frc2/command/CommandPtr.h>
#include <frc2/command/InstantCommand.h>
#include <frc2/command/WaitCommand.h>

#include "subsystems/AFCClimber.h"
#pragma endregion

class AFCClimberComm : public frc2::CommandHelper<frc2::Command, AFCClimberComm>
{
    public:
        explicit AFCClimberComm(AFCClimber* climb, ClimberStates state);

        void Initialize() override;
        bool IsFinished() override;

    private:
        AFCClimber* m_climber;
        ClimberStates m_state;
        
};