#pragma once

#pragma region Includes
#include <frc2/command/CommandPtr.h>
#include <frc2/command/InstantCommand.h>
#include <frc2/command/WaitCommand.h>

#include "subsystems/AFCIntake.h"
#pragma endregion

frc2::CommandPtr IntakeSetState(AFCIntake* );