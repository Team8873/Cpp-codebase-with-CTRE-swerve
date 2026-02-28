#include "misc/MaxMotorConfig.h"

void MaxMotorConfig(rev::spark::SparkMax *motor,
                    units::ampere_t currentLimit,
                    bool breakMode,
                    double P,
                    double I,
                    double D,
                    double S,
                    double V,
                    double A,
                    bool onboard,
                    bool continuousWrap)
{
    rev::spark::SparkMaxConfig sparkMaxConfig{};

    sparkMaxConfig.SetIdleMode(breakMode ? rev::spark::SparkBaseConfig::IdleMode::kBrake : rev::spark::SparkBaseConfig::IdleMode::kCoast);
    sparkMaxConfig.SmartCurrentLimit(currentLimit.value());

    if(onboard) {
        sparkMaxConfig.closedLoop.SetFeedbackSensor(rev::spark::FeedbackSensor::kPrimaryEncoder);
    }
    else {
        sparkMaxConfig.closedLoop.SetFeedbackSensor(rev::spark::FeedbackSensor::kDetachedAbsoluteEncoder, 14);  // ♦♦♦CHANGE THIS LATER♦♦♦ This sets the off-board encoder's ID 
        sparkMaxConfig.absoluteEncoder.PositionConversionFactor(360.0);
        sparkMaxConfig.absoluteEncoder.VelocityConversionFactor(360.0 / 60.0);
    }                                                                                                         
    sparkMaxConfig.closedLoop.Pid(P, I, D);
    sparkMaxConfig.closedLoop.PositionWrappingEnabled(continuousWrap);
    auto status = motor->Configure(
            sparkMaxConfig,
            rev::ResetMode::kNoResetSafeParameters,
            rev::PersistMode::kPersistParameters);
}
