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
        sparkMaxConfig.encoder.PositionConversionFactor(17.5);
    }
    else {
        sparkMaxConfig.closedLoop.SetFeedbackSensor(rev::spark::FeedbackSensor::kPrimaryEncoder);
        sparkMaxConfig.encoder.PositionConversionFactor(17.5);
    }                                                                                                         
    sparkMaxConfig.closedLoop.Pid(P, I, D);
    //sparkMaxConfig.closedLoop.feedForward.kS(S);//.kV(V).kA(A);
    sparkMaxConfig.closedLoop.PositionWrappingEnabled(continuousWrap);
    auto status = motor->Configure(
            sparkMaxConfig,
            rev::ResetMode::kNoResetSafeParameters,
            rev::PersistMode::kPersistParameters);
}
