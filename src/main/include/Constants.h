#pragma once

#include <units/length.h>
#include <units/time.h>
#include <units/velocity.h>

#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableInstance.h"

 typedef int CANid_t;
 
 #pragma region ConstantsCanIds
 namespace ConstantsCanIds
 {
    constexpr CANid_t TurretID = 17;
    constexpr CANid_t ShooterID = 16;
    constexpr CANid_t TurretEncoderId = 55;
 };