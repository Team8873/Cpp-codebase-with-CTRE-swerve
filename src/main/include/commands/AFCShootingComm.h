#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/CommandHelper.h>

#include <chrono>

#include "subsystems/AFCIndexer.h"
#include "subsystems/AFCFlywheel.h"
#include "subsystems/AFCShooter.h"
#include "subsystems/AFCVision.h"

class AFCShootingComm : public frc2::CommandHelper<frc2::Command, AFCShootingComm> {
    public:
        AFCShootingComm(AFCIndexer* indexerSubsystem, 
                        AFCFlywheel* flywheelSubsystem,
                        AFCShooter* shooterSubsystem,
                        AFCVision* visionSubsystem);

        void Initialize() override;

        void Execute() override;

        void End(bool interrupted) override;

        bool IsFinished() override;


    private:
        AFCIndexer* m_pIndexerSubsystem;
        AFCFlywheel* m_pFlywheelSubsytem;
        AFCShooter* m_pShootersubsystem;
        AFCVision* m_pVisionsubsystem;
        std::chrono::time_point<std::chrono::steady_clock> m_startTime;
};