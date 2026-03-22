#pragma once

#include <frc2/command/CommandPtr.h>
#include <frc2/command/InstantCommand.h>
#include <frc2/command/WaitCommand.h>
#include <chrono>
#include "subsystems/AFCClimber.h"

class AFCClimberComm : public frc2::CommandHelper<frc2::Command, AFCClimberComm>
{
    public:
        explicit AFCClimberComm(AFCClimber* climb);

        void Initialize() override;

        void Execute() override;

        void End(bool interrupted) override;
        
        bool IsFinished() override;

    private:
        AFCClimber* m_pClimber;
        std::chrono::time_point<std::chrono::steady_clock> m_startTime;
        
        
};