/******************************************************************************
 * Copyright (c) LedStripController 2016. All rights reserved.                *
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

#ifndef LEDSTRIPCONTROLLER_LEDSTRIPADAPTERLPD8806_H
#define LEDSTRIPCONTROLLER_LEDSTRIPADAPTERLPD8806_H

#include "LPD8806.h"
#include "BaseLedStripAdapter.h"

#define LPD8806_COLOR_CHANNEL_COUNT 3
#define LPD8806_COLOR_VALUE_MAX 127

class LedStripAdapterLPD8806 : public BaseLedStripAdapter {
private:
    /**
     * LPD8806 strip instance.
     */
    LPD8806 strip;

public:
    /**
     * Constructor.
     *
     * @param ledCount Number of LEDs.
     * @param pinData Data pin.
     * @param pinClock Clock pin.
     */
    LedStripAdapterLPD8806(uint8_t ledCount, uint8_t pinData, uint8_t pinClock);

    // Override virtual method in BaseLedStripAdapter class
    void setLedColor(uint8_t ledIndex, uint8_t redChannel);

    // Override virtual method in BaseLedStripAdapter class
    void setLedColor(uint8_t ledIndex, uint8_t redChannel, uint8_t greenChannel);

    // Override virtual method in BaseLedStripAdapter class
    void setLedColor(uint8_t ledIndex, uint8_t redChannel, uint8_t greenChannel, uint8_t blueChannel);

    // Override virtual method in BaseLedStripAdapter class
    void setLedColor(uint8_t ledIndex, uint8_t redChannel, uint8_t greenChannel, uint8_t blueChannel, uint8_t alphaChannel);

    // Override virtual method in BaseLedStripAdapter class
    void setLedColorCombinedChannels(uint8_t ledIndex, uint32_t combinedColorValue);

    /**
     * Get the number of color channels this LED strip has.
     */
    uint8_t getColorChannelCount();

    /**
     * Get the maximum color value for each color channel on this LED strip.
     */
    uint8_t getColorValueMax();
};

#endif // LEDSTRIPCONTROLLER_LEDSTRIPADAPTERLPD8806_H