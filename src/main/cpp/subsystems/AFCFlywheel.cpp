#include "subsystems/AFCFlywheel.h"

AFCFlywheel::AFCFlywheel(){

    TalonMotorConfig(&m_shooter1,
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

    
    TalonMotorConfig(&m_shooter2,
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

}

void AFCFlywheel::Periodic(){
    auto velocitySignal = m_shooter1.GetVelocity();
    double velocity = velocitySignal.GetValueAsDouble();
    frc::SmartDashboard::PutNumber("Shooter Velocity", velocity);
}

void AFCFlywheel::Idle(){
    m_shooter1.SetControl(ctre::phoenix6::controls::VelocityVoltage{22_tps});
    m_shooter2.SetControl(ctre::phoenix6::controls::VelocityVoltage{-22_tps});
    //m_shooter1.Set(0.5);
    //m_shooter2.Set(-0.5);\[]
    
    
}

void AFCFlywheel::SpinUp(double Sspeed){
    m_shooter1.SetControl(ctre::phoenix6::controls::VelocityVoltage{70_tps});
    m_shooter2.SetControl(ctre::phoenix6::controls::VelocityVoltage{-70_tps});
    //m_shooter1.Set(Sspeed);
    //m_shooter2.Set(-Sspeed);
    //m_shooter1.SetControl(m_velReq.WithVelocity(50_tr / 1_s));
    //m_shooter2.SetControl(m_velReq.WithVelocity(-50_tr / 1_s));
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

void AFCFlywheel::AutoSpeed(double Sspeed){

units::turns_per_second_t speed = units::turns_per_second_t{Sspeed};

    m_shooter1.SetControl(ctre::phoenix6::controls::VelocityVoltage{speed});
    m_shooter2.SetControl(ctre::phoenix6::controls::VelocityVoltage{-speed});

//     if (Sspeed < 2.4){
//         m_shooter1.SetControl(ctre::phoenix6::controls::VelocityVoltage{55_tps});
//         m_shooter2.SetControl(ctre::phoenix6::controls::VelocityVoltage{-55_tps});
//     }  else if (Sspeed >= 2.4 && Sspeed < 3.4) {
//          m_shooter1.SetControl(ctre::phoenix6::controls::VelocityVoltage{65_tps});
//          m_shooter2.SetControl(ctre::phoenix6::controls::VelocityVoltage{-65_tps});
//     } else if (Sspeed >= 3.4 && Sspeed < 4.4) {
//          m_shooter1.SetControl(ctre::phoenix6::controls::VelocityVoltage{75_tps});
//          m_shooter2.SetControl(ctre::phoenix6::controls::VelocityVoltage{-75_tps});
// } else if (Sspeed >= 4.4 ) {
//          m_shooter1.SetControl(ctre::phoenix6::controls::VelocityVoltage{90_tps});
//          m_shooter2.SetControl(ctre::phoenix6::controls::VelocityVoltage{-90_tps});
// }
}

void AFCFlywheel::ManualSpeed(double Sspeed){
    if (Sspeed < -0.5){
        m_shooter1.SetControl(ctre::phoenix6::controls::VelocityVoltage{55_tps});
        m_shooter2.SetControl(ctre::phoenix6::controls::VelocityVoltage{-55_tps});
       // m_hoodServos.Set(0);
    }  else if (Sspeed >= -0.5 && Sspeed <= 0.5) {
         m_shooter1.SetControl(ctre::phoenix6::controls::VelocityVoltage{65_tps});
         m_shooter2.SetControl(ctre::phoenix6::controls::VelocityVoltage{-65_tps});
         //m_hoodServos.Set(.5);
    } else if (Sspeed > 0.5) {
         m_shooter1.SetControl(ctre::phoenix6::controls::VelocityVoltage{75_tps});
         m_shooter2.SetControl(ctre::phoenix6::controls::VelocityVoltage{-75_tps});
         //m_hoodServos.Set(1);
} 

}

void AFCFlywheel::SuperShoot(){

         m_shooter1.SetControl(ctre::phoenix6::controls::VelocityVoltage{100_tps});
         m_shooter2.SetControl(ctre::phoenix6::controls::VelocityVoltage{-100_tps});

}