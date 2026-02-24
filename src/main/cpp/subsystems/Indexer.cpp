#include "subsystems/Indexer.h"



Indexer::Indexer()
{
    MaxMotorConfig(&m_conveyorMotor,
                    40.0_A,  // Max Amp
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


double conveyorSpeed = 0;
double uptakeSpeed = 0;


void Indexer::Periodic(){
    //frc::SmartDashboard::PutString("Work", "Please");
}
void Indexer::Disable(){}

void Indexer::ConveyorOn(){
    m_conveyorMotor.Set(0.5);
}

void Indexer::ConveyorOff(){ 
    m_conveyorMotor.StopMotor();
}

void Indexer::UptakeOn(bool argument){
    if (argument){
       m_uptakeMotor.Set(-0.5);
    }
}

void Indexer::UptakeOff(){
    m_uptakeMotor.StopMotor();
}

void Indexer::Stop(){
    m_conveyorMotor.StopMotor();
    m_uptakeMotor.StopMotor();
}
