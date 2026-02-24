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
    constexpr CANid_t TurretMotorID = 15;
    constexpr CANid_t ShooterMotor1ID = 9;
    constexpr CANid_t ShooterMotor2ID = 10;
 }