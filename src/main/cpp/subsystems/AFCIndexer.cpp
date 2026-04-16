#include "subsystems/AFCIndexer.h"



AFCIndexer::AFCIndexer()
{

    TalonMotorConfig(&m_uptaker,
                    40.0_A,
                    false,
                    true,
                    0.4,
                    0.0,
                    0.0,
                    0.0,
                    0.0,
                    0.0,
                    100.0_tps,
                    600.0_tr_per_s_sq);

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

    
    m_startTime = std::chrono::steady_clock::now();
}




void AFCIndexer::Periodic() {
 
}
void AFCIndexer::Disable(){

}

void AFCIndexer::ConveyorOn() {
    m_conveyorMotor.Set(0.5);
    m_uptaker.Set(0.0);
}
void AFCIndexer::UptakeReverse(){
    m_uptaker.Set(1.0);
    m_conveyorMotor.Set(-0.3);    

}

void AFCIndexer::UptakeOn() {
    //m_uptakeMotor.GetClosedLoopController().SetSetpoint(450, rev::spark::SparkLowLevel::ControlType::kVelocity);
    m_uptaker.Set(-1.0);
    m_conveyorMotor.Set(0.3);
    
    //m_kickerBarMotor.Set(-0.05);
}

// bool AFCIndexer::HopperEmpty(){
//     if (m_distanceSensor.GetRange() <= 5){

//     }
// }
// double AFCIndexer::GetDis(){
//     m_distanceSensor.GetRange();
// }
void AFCIndexer::Stop() {
    m_conveyorMotor.StopMotor();
    m_uptaker.StopMotor();
}

