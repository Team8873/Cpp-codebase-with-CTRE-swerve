#pragma once

#include <frc2/command/CommandPtr.h>
#include <frc2/command/InstantCommand.h>
#include <frc2/command/WaitCommand.h>

#include <chrono>

#include "subsystems/Shooter.h"

class ShooterComm : public frc2::CommandHelper<frc2::Command, ShooterComm>
{
    public:
        explicit ShooterComm(Shooter* shooterSubsystem);

        void Initialize() override;

        void Execute() override;

        void End(bool interupted) override;

        bool IsFinished() override;

        private:
            Shooter* m_pShooterSubsystem;

            std::chrono::time_point<std::chrono::steady_clock> m_startTime;
};