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

}

void AFCKicker::KickerOn(){
       m_kickerBarMotor.Set(-0.5);
}

void AFCKicker::KickerBack(){
    m_kickerBarMotor.Set(0.5);
}
 void AFCKicker::KickerJitter(){
    while(true){
    m_kickerBarMotor.Set(-0.5);
    frc2::cmd::Wait(0.3_s);
    m_kickerBarMotor.StopMotor();
    frc2::cmd::Wait(0.5_s);
    break;
    }
    
 }

void AFCKicker::Stop(){
    m_kickerBarMotor.StopMotor();
}