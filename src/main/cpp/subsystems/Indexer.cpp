#include "subsystems/Indexer.h"

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
                    0.0); // Acceleration constant
    MaxMotorConfig(&m_uptakeMotor,
                    40.0_A,  // Max Amp
                    true,// Brake mode
                    0.1, // Proportional gain
                    0.0, // Integral gain
                    0.0, // Derivative gain ♦♦DON'T TOUCH♦♦ (0.0)
                    0.0, // Static friction
                    0.0, // Velocity constant
                    0.0); // Acceleration constant
}
#pragma endregion


double conveyorSpeed = 0;
double uptakeSpeed = 0;


void Indexer::Periodic(){
    frc::SmartDashboard::PutString("Work", "Please");
}
void Indexer::Disable(){}

void Indexer::ConveyorOn(double speed){
    m_conveyorMotor.Set(speed);
}

void Indexer::ConveyorOff(double speed){ 
    m_conveyorMotor.StopMotor();
}

void Indexer::UptakeOn(double speed){
    m_uptakeMotor.Set(speed);
}

void Indexer::UptakeOff(double speed){
    m_uptakeMotor.StopMotor();
}

void Indexer::Stop(){
    m_conveyorMotor.StopMotor();
    m_uptakeMotor.StopMotor();
}
