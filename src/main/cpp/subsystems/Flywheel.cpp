#include "subsystems/Flywheel.h"

Flywheel::Flywheel(){

    TalonMotorConfig(&m_shooter1,
                    40.0_A,
                    true,
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
                    true,
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

void Flywheel::Periodic(){
    auto velocitySignal = m_shooter1.GetVelocity();
    double velocity = velocitySignal.GetValueAsDouble();
    frc::SmartDashboard::PutNumber("Shooter Velocity", velocity);
}

void Flywheel::Idle(){
    m_shooter1.Set(0.5);
    m_shooter2.Set(-0.5);
}

void Flywheel::SpinUp(double Sspeed){
    m_shooter1.Set(Sspeed);
    m_shooter2.Set(-Sspeed);
};

void Flywheel::Disable(){
    m_shooter1.Disable();
    m_shooter2.Disable();
};