#include "subsystems/AFCIndexer.h"



AFCIndexer::AFCIndexer()
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
                    true,
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
                    true,
                    true);
}




void AFCIndexer::Periodic() {

}
void AFCIndexer::Disable(){

}

void AFCIndexer::ConveyorOn() {
    m_conveyorMotor.Set(0.5);
    m_uptakeMotor.Set(0.0);
}

void AFCIndexer::UptakeOn() {
    //m_uptakeMotor.GetClosedLoopController().SetSetpoint(450, rev::spark::SparkLowLevel::ControlType::kVelocity);
    m_uptakeMotor.Set(-1);
    m_conveyorMotor.Set(-0.5);
}

void AFCIndexer::Stop() {
    m_conveyorMotor.StopMotor();
    m_uptakeMotor.StopMotor();
}

