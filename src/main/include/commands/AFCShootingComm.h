#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/CommandHelper.h>

#include <chrono>

#include "subsystems/AFCIndexer.h"
#include "subsystems/AFCFlywheel.h"

class AFCShootingComm : public frc2::CommandHelper<frc2::Command, AFCShootingComm> {
    public:
        AFCShootingComm(AFCIndexer* indexerSubsystem, AFCFlywheel* flywheelSubsystem);

        void Initialize() override;

        void Execute() override;

        void End(bool interrupted) override;

        bool IsFinished() override;


    private:
        AFCIndexer* m_pIndexerSubsystem;
        AFCFlywheel* m_pFlywheelSubsytem;
        std::chrono::time_point<std::chrono::steady_clock> m_startTime;
};