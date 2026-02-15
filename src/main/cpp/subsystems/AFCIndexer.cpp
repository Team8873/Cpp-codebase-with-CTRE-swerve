#include "subsystems/AFCIndexer.h"

#pragma region Constructor

Indexer::Indexer()
{
    MaxMotorConfig(&m_conveyorMotor,
                    30.0_A,  // Max Amp
                    true,// Brake mode
                    0.1, // Proportional gain
                    0.0, // Integral gain
                    0.0, // Derivative gain ♦♦DON'T TOUCH♦♦ (0.0)
                    0.0, // Static friction
                    0.0, // Velocity constant
                    0.0, // Acceleration constant
                    true);
    MaxMotorConfig(&m_uptakeMotor,
                    40.0_A,  // Max Amp
                    true,// Brake mode
                    0.1, // Proportional gain
                    0.0, // Integral gain
                    0.0, // Derivative gain ♦♦DON'T TOUCH♦♦ (0.0)
                    0.0, // Static friction
                    0.0, // Velocity constant
                    0.0, // Acceleration constant
                    true);
}
#pragma endregion

#pragma region SetState

double conveyorSpeed = 0;
double uptakeSpeed = 0;

void Indexer::Periodic() {

}
void Indexer::Disable(){

}

void Indexer::ConveyorOn(double speed) {
    m_conveyorMotor.Set(speed);
}

void Indexer::ConverorOff(double speed) {
    m_conveyorMotor.Set(speed);
}
void Indexer::UptakeOn(double speed) {
    m_uptakeMotor.Set(speed);
}
void Indexer::UptakeOff(double speed) {
    m_uptakeMotor.Set(speed);
}
void Indexer::Stop() {
    m_conveyorMotor.Set(0.0);
    m_uptakeMotor.Set(0.0);
}

