#pragma once

#include <frc2/command/CommandPtr.h>
#include <frc2/command/InstantCommand.h>
#include <frc2/command/WaitCommand.h>

#include <chrono>

#include "subsystems/AFCIntake.h"

class AFCJiggleComm : public frc2::CommandHelper<frc2::Command, AFCJiggleComm>
{
    public:
        explicit AFCJiggleComm(AFCIntake* intakeSubsystem);

        void Initialize() override;

        void Execute() override;

        void End(bool interrupted) override;
        
        bool IsFinished() override;

    private:
        AFCIntake* m_pIntake;
        std::chrono::time_point<std::chrono::steady_clock> m_startTime;

};