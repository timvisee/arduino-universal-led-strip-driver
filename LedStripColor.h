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

#ifndef LEDSTRIPDRIVER_LEDSTRIPCOLOR_H
#define LEDSTRIPDRIVER_LEDSTRIPCOLOR_H

#include "LedStripDriver.h"

#define LED_STRIP_COLOR_VALUE_SIZE 256
#define LED_STRIP_COLOR_VALUE_MAX LED_STRIP_COLOR_VALUE_SIZE - 1
#define LED_STRIP_COLOR_WHEEL_SIZE LED_STRIP_COLOR_VALUE_SIZE * 3
#define LED_STRIP_COLOR_WHEEL_SMALL_SIZE LED_STRIP_COLOR_VALUE_SIZE / 2 * 3

/**
 * LED strip color class representing a color used by the LED strip driver.
 *
 * @author Tim Visee
 * @website http://timvisee.com/
 */
class LedStripColor {
private:
    /**
     * Red channel intensity.
     */
    uint8_t redChannel;

    /**
     * Green channel intensity.
     */
    uint8_t greenChannel;

    /**
     * Blue channel intensity.
     */
    uint8_t blueChannel;

    /**
     * Alpha channel intensity.
     */
    uint8_t alphaChannel;

public:
    /**
     * Constructor.
     * This will default to black. The alpha channel is set to the maximum value.
     */
    LedStripColor();

    /**
     * Constructor.
     *
     * @param redChannel Red channel intensity.
     */
    LedStripColor(uint8_t redChannel);

    /**
     * Constructor.
     *
     * @param redChannel Red channel intensity.
     * @param greenChannel Green channel intensity.
     */
    LedStripColor(uint8_t redChannel, uint8_t greenChannel);

    /**
     * Constructor.
     *
     * @param redChannel Red channel intensity.
     * @param greenChannel Green channel intensity.
     * @param blue Blue channel intensity.
     */
    LedStripColor(uint8_t redChannel, uint8_t greenChannel, uint8_t blueChannel);

    /**
     * Constructor.
     *
     * @param redChannel Red channel intensity.
     * @param greenChannel Green channel intensity.
     * @param blue Blue channel intensity.
     * @param alpha Alpha channel intensity.
     */
    LedStripColor(uint8_t redChannel, uint8_t greenChannel, uint8_t blueChannel, uint8_t alphaChannel);

    /**
     * Destructor.
     */
    ~LedStripColor();

    /**
     * Constructor helper for combined color channels.
     *
     * @param combined Combined color channels.
     *
     * @return Color instance.
     */
    static LedStripColor fromCombinedChannels(uint32_t combined);

    /**
     * Constructor helper to create a color instance using a color wheel from the given value.
     * This uses a small wheel.
     *
     * @param value Color wheel position. (0 to 384)
     *
     * @return Color instance.
     */
    static LedStripColor fromSmallWheel(uint16_t position);

    /**
     * Constructor helper to create a color instance using a color wheel from the given value.
     *
     * @param value Color wheel position. (0 to 765)
     *
     * @return Color instance.
     */
    static LedStripColor fromWheel(uint16_t position);

    /**
     * LED strip color instance representing black.
     */
    static LedStripColor black();

    /**
     * LED strip color instance representing white.
     */
    static LedStripColor white();

    /**
     * LED strip color instance representing red.
     */
    static LedStripColor red();

    /**
     * LED strip color instance representing green.
     */
    static LedStripColor green();

    /**
     * LED strip color instance representing blue.
     */
    static LedStripColor blue();

    /**
     * Get the red channel intensity.
     *
     * @return Channel intensity.
     */
    uint8_t getRed();

    /**
     * Set the red channel intensity.
     *
     * @param redChannel Red channel intensity.
     */
    void setRed(uint8_t redChannel);

    /**
     * Get the green channel intensity.
     *
     * @return Channel intensity.
     */
    uint8_t getGreen();

    /**
     * Set the green channel intensity.
     *
     * @param greenChannel Green channel intensity.
     */
    void setGreen(uint8_t greenChannel);

    /**
     * Get the blue channel intensity.
     *
     * @return Channel intensity.
     */
    uint8_t getBlue();

    /**
     * Set the blue channel intensity.
     *
     * @param blueChannel Blue channel intensity.
     */
    void setBlue(uint8_t blueChannel);

    /**
     * Get the alpha channel intensity.
     *
     * @return Channel intensity.
     */
    uint8_t getAlpha();

    /**
     * Set the alpha channel intensity.
     *
     * @param redChannel Alpha channel intensity.
     */
    void setAlpha(uint8_t alphaChannel);

    /**
     * Get the combined color channel values.
     *
     * @return Combined color channel values.
     */
    uint32_t getCombinedChannels();

    /**
     * Get the combined color channel values.
     *
     * @param combined Combined color channel values.
     */
    uint32_t setCombinedChannels(uint32_t combined);
};

#endif // LEDSTRIPDRIVER_LEDSTRIPCOLOR_H
