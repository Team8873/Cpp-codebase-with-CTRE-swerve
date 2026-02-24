#pragma once

#pragma region Includes
#include <frc2/command/CommandPtr.h>
#include <frc2/command/InstantCommand.h>
#include <frc2/command/WaitCommand.h>

#include <chrono>


#include "subsystems/AFCIntake.h"
#pragma endregion

class AFCIntakeComm : public frc2::CommandHelper<frc2::Command, AFCIntakeComm>
{
    public:
        explicit AFCIntakeComm(AFCIntake* intakeSubsystem, double angleOfDangle);

        void Initialize() override;

        void Execute() override;

        void End(bool interrupted) override;
        
        bool IsFinished() override;

    private:
        AFCIntake* m_pIntake;
        std::chrono::time_point<std::chrono::steady_clock> m_startTime;
        const double m_pAngleOfDangle;
};