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

#ifndef LEDSTRIPDRIVER_LEDSTRIPADAPTERLPD8806_H
#define LEDSTRIPDRIVER_LEDSTRIPADAPTERLPD8806_H

#include "LedStripLPD8806Helper.h"
#include "LedStripColor.h"
#include "LedStripAdapterBase.h"

#define LPD8806_COLOR_CHANNEL_COUNT 3
#define LPD8806_COLOR_VALUE_MAX 127

class LedStripAdapterLPD8806 : public BaseLedStripAdapter {
private:
    /**
     * LPD8806 strip instance.
     */
    LPD8806* strip;

public:
    /**
     * Constructor.
     *
     * @param ledCount Number of LEDs.
     * @param pinData Data pin.
     * @param pinClock Clock pin.
     */
    LedStripAdapterLPD8806(uint16_t ledCount, uint8_t pinData, uint8_t pinClock);

    /**
     * Destructor.
     */
    ~LedStripAdapterLPD8806();

    // Override virtual method in BaseLedStripAdapter class
    void init();

    // Override virtual method in BaseLedStripAdapter class
    void init(bool render);

    // Override virtual method in BaseLedStripAdapter class
    void render();

    // Override virtual method in BaseLedStripAdapter class
    uint16_t getLedCount();

    // Override virtual method in BaseLedStripAdapter class
    void setLedCount(uint16_t ledCount);

    // Override virtual method in BaseLedStripAdapter class
    LedStripColor getLedColor(uint16_t ledIndex);

    // Override virtual method in BaseLedStripAdapter class
    void setLedColor(uint16_t ledIndex, LedStripColor color);

    // Override virtual method in BaseLedStripAdapter class
    void setLedColor(uint16_t ledIndex, uint8_t redChannel);

    // Override virtual method in BaseLedStripAdapter class
    void setLedColor(uint16_t ledIndex, uint8_t redChannel, uint8_t greenChannel);

    // Override virtual method in BaseLedStripAdapter class
    void setLedColor(uint16_t ledIndex, uint8_t redChannel, uint8_t greenChannel, uint8_t blueChannel);

    // Override virtual method in BaseLedStripAdapter class
    void setLedColor(uint16_t ledIndex, uint8_t redChannel, uint8_t greenChannel, uint8_t blueChannel, uint8_t alphaChannel);

    // Override virtual method in BaseLedStripAdapter class
    uint32_t getLedColorCombinedChannels(uint16_t ledIndex);

    // Override virtual method in BaseLedStripAdapter class
    void setLedColorCombinedChannels(uint16_t ledIndex, uint32_t combinedColorValue);

    // Override virtual method in BaseLedStripAdapter class
    uint8_t getColorChannelCount();

    // Override virtual method in BaseLedStripAdapter class
    uint8_t getColorValueMax();
};

#endif // LEDSTRIPDRIVER_LEDSTRIPADAPTERLPD8806_H
