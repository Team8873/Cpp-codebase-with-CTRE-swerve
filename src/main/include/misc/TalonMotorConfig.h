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

void TalonMotorConfig(ctre::phoenix6::hardware::TalonFX *motor);