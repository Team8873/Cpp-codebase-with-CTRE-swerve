#pragma once

#pragma region Includes
#include <iostream>
#include <numbers>
#include <units/angle.h>
#include <units/voltage.h>

#include <frc/RobotController.h>
#include <frc/RobotBase.h>
#include <frc/system/plant/LinearSystemId.h>
#include <frc/controller/SimpleMotorFeedforward.h>

#include <ctre/phoenix6/TalonFX.hpp>
#pragma endregion

void TalonMotorConfig(ctre::phoenix6::hardware::TalonFX *motor,
                      units::ampere_t currentLimit,
                      bool breakMode,
                      bool continuousWrap,
                      double                             P,
                      double                             I,
                      double                             D,
                      double                             S,
                      double                             V,
                      double                             A,
                          units::turns_per_second_t          velocityLimit,
                          units::turns_per_second_squared_t  accelerationLimit,
                          double                             sensorToMechanismRatio = 1.0);