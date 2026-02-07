#include "misc/MaxMotorConfig.h"

#pragma region MaxMotorConfig
void MaxMotorConfig(rev::spark::SparkMax *motor,
                    units::ampere_t currentLimit,
                    bool breakMode,
                    double P,
                    double I,
                    double D,
                    double S,
                    double V,
                    double A)
{
    rev::spark::SparkMaxConfig sparkMaxConfig{};

    sparkMaxConfig.SetIdleMode(breakMode ? rev::spark::SparkBaseConfig::IdleMode::kBrake : rev::spark::SparkBaseConfig::IdleMode::kCoast);
    sparkMaxConfig.SmartCurrentLimit(currentLimit.value());

    sparkMaxConfig.closedLoop.SetFeedbackSensor(rev::spark::FeedbackSensor::kPrimaryEncoder);
    sparkMaxConfig.closedLoop.Pid(P, I, D);
    //sparkMaxConfig.closedLoop.PositionWrappingEnabled(continuousWrap);
    auto status = motor->Configure(
            sparkMaxConfig,
            rev::ResetMode::kNoResetSafeParameters,
            rev::PersistMode::kPersistParameters);
}
#pragma endregion