#pragma once

#include <frc2/command/CommandPtr.h>
#include <frc2/command/InstantCommand.h>
#include <frc2/command/WaitCommand.h>

#include <chrono>

#include "subsystems/AFCKicker.h"

class AFCKickerComm : public frc2::CommandHelper<frc2::Command, AFCKickerComm>
{
    public: 
        explicit AFCKickerComm(AFCKicker* kickerSubsystem);

        void Initialize() override;

        void Execute() override;

        void End(bool interrupted) override;

        bool IsFinished() override;

    private:
        AFCKicker* m_pKickerSubsystem;

};
