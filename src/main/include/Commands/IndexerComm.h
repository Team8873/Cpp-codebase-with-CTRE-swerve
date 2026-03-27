#pragma once

#include <frc2/command/CommandPtr.h>
#include <frc2/command/InstantCommand.h>
#include <frc2/command/WaitCommand.h>

#include <chrono>

#include "subsystems/Indexer.h"
#include "subsystems/Shooter.h"


class IndexerComm : public frc2::CommandHelper<frc2::Command, IndexerComm>
{
    public:
        explicit IndexerComm(Indexer* indexerSubsystem, Shooter* shooterSubsytem);
    
        void Initialize() override;

        void Execute() override;

        void End(bool interrupted) override;

        bool IsFinished() override;

    private:
        Indexer* m_pIndexerSubsytem;
        Shooter* m_pShooterSubsytem;

        std::chrono::time_point<std::chrono::steady_clock> m_startTime;
        
};