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

#ifndef LEDSTRIPCONTROLLER_LEDSTRIPCOLOR_H
#define LEDSTRIPCONTROLLER_LEDSTRIPCOLOR_H

#include "Arduino.h"

#define LED_STRIP_COLOR_VALUE_MAX 127

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
     * Constructor helper for combined color channels.
     *
     * @param combined Combined color channels.
     */
    static LedStripColor fromCombinedChannels(uint32_t combined);

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

#endif // LEDSTRIPCONTROLLER_LEDSTRIPCOLOR_H
