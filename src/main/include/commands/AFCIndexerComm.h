#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/CommandHelper.h>

#include <chrono>

#include "subsystems/AFCIndexer.h"

class AFCIndexerComm : public frc2::CommandHelper<frc2::Command, AFCIndexerComm> {
    public:
        AFCIndexerComm(Indexer* indexerSubsystem, bool OnOff = false);

        void Initialize() override;

        void Execute() override;

        void End(bool interrupted) override;

        bool IsFinished() override;


    private:
        Indexer* m_pIndexerSubsystem;
        std::chrono::time_point<std::chrono::steady_clock> m_startTime;
        //IndexerConstant m_indexerConstant;
        const bool m_onOff;
};