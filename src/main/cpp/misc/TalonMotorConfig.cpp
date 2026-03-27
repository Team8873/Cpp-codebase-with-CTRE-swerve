#include "misc/TalonMotorConfig.h"

void TalonMotorConfig(ctre::phoenix6::hardware::TalonFX *motor,
                            units::ampere_t currentLimit,
                            bool breakMode,
                            bool continuousWrap,
                            double P,
                            double I,
                            double D,
                            double S,
                            double V,
                            double A,
                            units::turns_per_second_t velocityLimit,
                            units::turns_per_second_squared_t accelerationLimit)
{
    ctre::phoenix6::configs::TalonFXConfiguration talonFXConfiguration{};

    talonFXConfiguration.ClosedLoopGeneral.ContinuousWrap = continuousWrap;
    ctre::phoenix6::configs::FeedbackConfigs &feedbackConfigs = talonFXConfiguration.Feedback;
    ctre::phoenix6::configs::MotorOutputConfigs &motorOutputConfigs = talonFXConfiguration.MotorOutput;
    motorOutputConfigs.NeutralMode = breakMode
        ? ctre::phoenix6::signals::NeutralModeValue::Brake
        : ctre::phoenix6::signals::NeutralModeValue::Coast;

    ctre::phoenix6::configs::CurrentLimitsConfigs &currentLimitsConfigs = talonFXConfiguration.CurrentLimits;
    currentLimitsConfigs.SupplyCurrentLimit       = currentLimit;
    currentLimitsConfigs.SupplyCurrentLimitEnable = true;

    ctre::phoenix6::configs::Slot0Configs &slot0Configs = talonFXConfiguration.Slot0;
    slot0Configs.kP = P;
    slot0Configs.kI = I;
    slot0Configs.kD = D;
    slot0Configs.kS = S;
    slot0Configs.kV = V;
    slot0Configs.kA = A;

    ctre::phoenix6::configs::MotionMagicConfigs &motionMagicConfigs = talonFXConfiguration.MotionMagic;
    motionMagicConfigs.MotionMagicCruiseVelocity = units::turns_per_second_t{velocityLimit};
    motionMagicConfigs.MotionMagicAcceleration   = units::turns_per_second_squared_t{accelerationLimit};
    motionMagicConfigs.MotionMagicJerk           = units::turns_per_second_cubed_t{0.0};
}