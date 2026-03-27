#pragma once

#pragma region Includes

#include <units/length.h>
#include <units/time.h>
#include <units/velocity.h>

#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableInstance.h"

#pragma endregion
 
#pragma region ConstantsCanIds

typedef int CANid_t;
   namespace ConstantsCanIds{
    constexpr CANid_t TurretID = 17;
      constexpr CANid_t ShooterID = 18; //ID 17 is the testing/turret motor (for now)
         constexpr CANid_t TurretEncoderId = 18;
            constexpr CANid_t ShooterEncoderId = 19;
};
 #pragma endregionxn