#pragma once

#include <units/length.h>
#include <units/time.h>
#include <units/velocity.h>

#include <rev/SparkLowLevel.h>

#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableInstance.h"

typedef int CANid_t;


#pragma region ConstantsCanIds
namespace ConstantsCanIds
{
   constexpr CANid_t IntakeMotorId = 12;
   constexpr CANid_t IntakeDeployerId = 13;
   constexpr CANid_t IntakeEncoderId = 14; 
   constexpr CANid_t ClimberMotor = 15;
}

#pragma endregion

