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
   constexpr CANid_t UptakerMotorID = 21;   // Intake Motor CAN ID    ♦ Kraken x60
   constexpr CANid_t IntakerMotorID = 20;   // Intake Motor CAN ID    ♦ Kraken x60
   constexpr CANid_t ShooterMotor1Id = 9;   // Shooter Motor 1 CAN ID ♦ Kraken x60
   constexpr CANid_t ShooterMotor2Id = 10;  // Shooter Motor 2 CAN ID ♦ Kraken x60
   constexpr CANid_t ConveyorMotorId = 11;  // Conveyor Motor CAN ID  ♦ SparkMax
   constexpr CANid_t IntakeDeployerId = 12; // Deployer Motor CAN ID  ♦ SparkMax
   constexpr CANid_t IntakeMotorId = 13;    // Intake Motor CAN ID    ♦ SparkMAx ♦♦♦ NOT USED ♦♦♦
   constexpr CANid_t UptakeMotorId = 14;    // UpTake Motor CAN ID    ♦ SparkMax ♦♦♦ NOT USED ♦♦♦
   constexpr CANid_t TurretMotorId = 15;    // Turret Motor CAN ID    ♦ SparkMax
   constexpr CANid_t ClimberMotorId = 16;   // Climber Motor CAN ID   ♦ SparkMax ♦♦♦ NOT USED ♦♦♦
   constexpr CANid_t KickerBarMotorId = 17;

   constexpr CANid_t IntakeEncoderId = 14; //CTRE CAN devices can share ids with
   constexpr CANid_t CANdleId = 15;        //others as long as it is a different device
   
}


