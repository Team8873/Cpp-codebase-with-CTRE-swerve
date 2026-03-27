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
   constexpr CANid_t IntakeMotorId = 400;
   constexpr CANid_t IntakeDeployerId = 401;
   constexpr CANid_t IntakeEncoderId = 14; 
   constexpr CANid_t ClimberMotor = 15;

   constexpr CANid_t conveyorMotorID = 17;
   constexpr CANid_t uptakeMotorID = 18;

   constexpr CANid_t ShooterMotor1Id = 300;
   constexpr CANid_t ShooterMotor2Id = 301;
   constexpr CANid_t TurretMotorId = 302;

}


