#include "subsystems/AFCFlywheel.h"

AFCFlywheel::AFCFlywheel(){

    TalonMotorConfig(&m_shooter1,
                    40.0_A,
                    false,
                    0.1,
                    0.0,
                    0.0,
                    0.0,
                    0.0,
                    0.0,
                    0.0,
                    0.0_tps,
                    0.0_tr_per_s_sq);

    
    TalonMotorConfig(&m_shooter2,
                    40.0_A,
                    false,
                    0.1,
                    0.0,
                    0.0,
                    0.0,
                    0.0,
                    0.0,
                    0.0,
                    0.0_tps,
                    0.0_tr_per_s_sq);

}

void AFCFlywheel::Periodic(){
    auto velocitySignal = m_shooter1.GetVelocity();
    double velocity = velocitySignal.GetValueAsDouble();
    frc::SmartDashboard::PutNumber("Shooter Velocity", velocity);
}

void AFCFlywheel::Idle(){
    m_shooter1.Set(0.5);
    m_shooter2.Set(-0.5);
}

void AFCFlywheel::SpinUp(double Sspeed){
    m_shooter1.Set(Sspeed);
    m_shooter2.Set(-Sspeed);
};

bool AFCFlywheel::Flywheelrpm(){   
    bool upToSpeed = false;
    if (m_shooter1.GetVelocity().GetValueAsDouble() >= 500){
        upToSpeed = true;
    }
    else{
        upToSpeed = false;
    }
    return (upToSpeed);
}
void AFCFlywheel::Disable(){
    m_shooter1.Disable();
    m_shooter2.Disable();
}