#pragma once

#pragma region Includes
#include <frc2/command/CommandPtr.h>
#include <frc2/command/InstantCommand.h>
#include <frc2/command/WaitCommand.h>

#include "subsystems/AFCIntake.h"
#pragma endregion

class AFCIntakeComm : public frc2::CommandHelper<frc2::Command, AFCIntakeComm>
{
    public:
        explicit AFCIntakeComm(AFCIntake* intake, IntakeStates state);

        void Initialize() override;
        bool IsFinished() override;

    private:
        AFCIntake* m_intake;
        IntakeStates m_state;
};