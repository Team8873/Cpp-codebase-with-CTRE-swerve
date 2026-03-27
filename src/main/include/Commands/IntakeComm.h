#pragma once

#include <frc2/command/CommandPtr.h>
#include <frc2/command/InstantCommand.h>
#include <frc2/command/WaitCommand.h>

#include <chrono>

#include "subsystems/Intake.h"

class IntakeComm : public frc2::CommandHelper<frc2::Command, IntakeComm>
{
    public:
        explicit IntakeComm(Intake* intakeSubsystem);

        void Initialize() override;

        void Execute() override;

        void End(bool interrupted) override;

        bool IsFinished() override;
    
        private:
            Intake* m_pIntakeSubsytem;
            
            std::chrono::time_point<std::chrono::steady_clock> m_startTime;


};