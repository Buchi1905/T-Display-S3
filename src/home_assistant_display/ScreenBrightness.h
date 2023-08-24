#pragma once

#include "pin_config.h"
#include "esp32-hal.h"

static const uint8_t ledChan = 0U;

void ScreenBrightness_Init()
{
    
    ledcSetup(ledChan, 5000, 8);
    ledcAttachPin(PIN_LCD_BL, ledChan);
}

void ScreenBrightness_Set(uint8_t percent)
{
    int mappedValue = map(percent, 0, 100, 10, 254);
    ledcWrite(ledChan, mappedValue);
}
