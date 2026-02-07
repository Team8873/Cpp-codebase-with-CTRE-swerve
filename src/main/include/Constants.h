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
    constexpr CANid_t ConveyorMotorId = 17;
    constexpr CANid_t UptakeMotorId = 18;
}

#pragma endregion
 typedef int CANid_t;
 
 #pragma region ConstantsCanIds
 namespace ConstantsCanIds
 {
    constexpr CANid_t ShooterRotateID = 15;
    constexpr CANid_t ShooterDriverID = 16;
 }