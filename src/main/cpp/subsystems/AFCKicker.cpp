#include "subsystems/AFCKicker.h"

AFCKicker::AFCKicker()
{
MaxMotorConfig(&m_kickerBarMotor,
                    40.0_A,  // Max Amp
                    true,// Brake mode
                    0.004, // Proportional gain
                    0.0, // Integral gain
                    0.0, // Derivative gain ♦♦DON'T TOUCH♦♦ (0.0)
                    0.0, // Static friction
                    0.0, // Velocity constant
                    0.0, // Acceleration constant
                    true,
                    true);
                    m_startTime = std::chrono::steady_clock::now();

}

void AFCKicker::KickerOn(){
       m_kickerBarMotor.Set(-0.5);
}

void AFCKicker::KickerBack(){
    m_kickerBarMotor.Set(0.5);
}
 void AFCKicker::KickerJitter(){
    if((std::chrono::steady_clock::now() - m_startTime) < std::chrono::milliseconds(400)){
        m_kickerBarMotor.Set(-0.5);
    } else if((std::chrono::steady_clock::now() - m_startTime) >= std::chrono::milliseconds(400) and (std::chrono::steady_clock::now() - m_startTime) <= std::chrono::milliseconds(500)){
        m_kickerBarMotor.Set(0.5);
    } else{
        m_startTime = std::chrono::steady_clock::now();
    }
    // while(true){
    // m_kickerBarMotor.Set(-0.5);
    // frc2::cmd::Wait(0.3_s);
    // m_kickerBarMotor.StopMotor();    
    // frc2::cmd::Wait(0.5_s);
    // break;
    // }
    
    
 }

void AFCKicker::Stop(){
    m_kickerBarMotor.StopMotor();
}