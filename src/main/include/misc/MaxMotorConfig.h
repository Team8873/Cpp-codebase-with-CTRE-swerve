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

#include <rev/SparkMax.h>
#include <rev/SparkLowLevel.h>
#include <rev/config/SparkMaxConfig.h>
#pragma endregion

void MaxMotorConfig(rev::spark::SparkMax *motor,
                    units::ampere_t currentLimit,
                    bool breakMode,
                    double P,
                    double I,
                    double D,
                    double S,
                    double V,
                    double A,
                    bool onboard);