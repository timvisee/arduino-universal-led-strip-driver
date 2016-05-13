/******************************************************************************
 * Copyright (c) UniversalLedStripDriver 2016. All rights reserved.           *
 *                                                                            *
 * @author Tim Visee                                                          *
 * @website http://timvisee.com/                                              *
 *                                                                            *
 * Open Source != No Copyright                                                *
 *                                                                            *
 * Permission is hereby granted, free of charge, to any person obtaining a    *
 * copy of this software and associated documentation files (the "Software"), *
 * to deal in the Software without restriction, including without limitation  *
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,   *
 * and/or sell copies of the Software, and to permit persons to whom the      *
 * Software is furnished to do so, subject to the following conditions:       *
 *                                                                            *
 * The above copyright notice and this permission notice shall be included    *
 * in all copies or substantial portions of the Software.                     *
 *                                                                            *
 * You should have received a copy of The MIT License (MIT) along with this   *
 * program. If not, see <http://opensource.org/licenses/MIT/>.                *
 ******************************************************************************/

#ifndef LEDSTRIPDRIVER_LEDSTRIPLPD8806_H
#define LEDSTRIPDRIVER_LEDSTRIPLPD8806_H

#include "LedStripDriver.h"
#include "LedStripBase.h"
#include "LedStripAdapterLPD8806.h"

#include "LedStripLPD8806Helper.h"
#include "SPI.h"

/**
 * LedStrip class.
 * This class represents a physical LED strip, and provides an interface to control the strip.
 *
 * @author Tim Visee
 * @website http://timvisee.com/
 * @version 1.1
 */
class LedStripLPD8806 : public LedStripBase {
private:
    /**
     * Pin used for data transfer to the LED strip.
     */
    uint8_t pinData;

    /**
     * Pin used for the data clock signal.
     */
    uint8_t pinClock;

public:
    /**
     * Constructor.
     *
     * @param ledCount Number of LEDs on this LED strip.
     * @param pinData Arduino PIN for data.
     * @param pinClock Arduino PIN for clock.
     */
    LedStripLPD8806(uint16_t ledCount, uint8_t pinData, uint8_t pinClock);

#pragma clang diagnostic push
#pragma ide diagnostic ignored "HidingNonVirtualFunction"
    /**
     * Destructor.
     */
    ~LedStripLPD8806();
#pragma clang diagnostic pop

    /**
     * Get the Arduino pin used for the data signal.
     *
     * @return Data pin.
     */
    uint8_t getDataPin();

    /**
     * Get the Arduino pin used for the clock signal.
     *
     * @return Clock pin.
     */
    uint8_t getClockPin();

    // Override virtual method in BaseLedStrip class
    void init();

    // Override virtual method in BaseLedStrip class
    void init(bool render);

    // Override virtual method in BaseLedStrip class
    void render();
};

#endif // LEDSTRIPDRIVER_LEDSTRIPLPD8806_H
