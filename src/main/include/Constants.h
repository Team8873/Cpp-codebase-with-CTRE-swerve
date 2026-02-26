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
   constexpr CANid_t ShooterMotor1Id = 9;
   constexpr CANid_t ShooterMotor2Id = 10;
   constexpr CANid_t ConveyorMotorId = 11;
   constexpr CANid_t IntakeDeployerId = 12;
   constexpr CANid_t IntakeMotorId = 13;
   constexpr CANid_t UptakeMotorId = 14;//14
   constexpr CANid_t TurretMotorId = 15;//15
   constexpr CANid_t ClimberMotorId = 16;

   constexpr CANid_t IntakeEncoderId = 14; //CTRE CAN devices can share ids with
   constexpr CANid_t CANdleId = 15;        //others as long as it is a different device
   
}


