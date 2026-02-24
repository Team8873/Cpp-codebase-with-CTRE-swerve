#pragma once

#include <units/length.h>
#include <units/time.h>
#include <units/velocity.h>

#include <rev/SparkLowLevel.h>

#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableInstance.h"

typedef int CANid_t;



namespace ConstantsCanIds
{
   constexpr CANid_t IntakeMotorId = 12;
   constexpr CANid_t IntakeDeployerId = 13;
   constexpr CANid_t IntakeEncoderId = 14; 
   constexpr CANid_t ClimberMotorId = 19;
   constexpr CANid_t ConveyorMotorId = 18;
   constexpr CANid_t UptakeMotorId = 17;
   constexpr CANid_t TurretMotorId = 16;
   constexpr CANid_t ShooterMotor1Id = 21;
   constexpr CANid_t ShooterMotor2Id = 22;
}


