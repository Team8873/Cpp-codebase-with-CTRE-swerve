#include "subsystems/AFCLights.h"
#include "Robot.h"

AFCLights::AFCLights(){ 
}

void AFCLights::Periodic(){
}

void AFCLights::Disable(){
}

void AFCLights::SetColor(){
    m_candle.SetControl(controls::ColorFlowAnimation{0, 1000}
        .WithColor(ctre::phoenix6::signals::RGBWColor{255, 102, 200, 0})
    );
}

void AFCLights::HubShifts(){
    m_candle.SetControl(controls::SolidColor{0, 8}
        .WithColor(ctre::phoenix6::signals::RGBWColor{0, 0, 255, 0})
    );
}

void AFCLights::Intaking(){
    m_candle.SetControl(controls::ColorFlowAnimation{0, 8}
    );
}

void AFCLights::Targeting(){
    m_candle.SetControl(controls::StrobeAnimation{0, 1000}
        .WithColor(ctre::phoenix6::signals::RGBWColor{255, 102, 200, 0})
    );
}

void AFCLights::Stop(){
}