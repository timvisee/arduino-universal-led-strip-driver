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

#ifndef LEDSTRIPCONTROLLER_BASELEDSTRIPADAPTER_H
#define LEDSTRIPCONTROLLER_BASELEDSTRIPADAPTER_H

#include "LPD8806.h"

class BaseLedStripAdapter {
public:
    /**
     * Set the color using one color channel of the given LED on the strip.
     *
     * @param ledIndex Index of the LED to configure.
     * @param redChannel Color value of the red channel (first channel).
     */
    virtual void setLedColor(uint8_t ledIndex, uint8_t redChannel);

    /**
     * Set the color using two color channels of the given LED on the strip.
     *
     * @param ledIndex Index of the LED to configure.
     * @param redChannel Color value of the red channel (first channel).
     * @param greenChannel Color value of the green channel (second channel).
     */
    virtual void setLedColor(uint8_t ledIndex, uint8_t redChannel, uint8_t greenChannel);

    /**
     * Set the color using three color channels of the given LED on the strip.
     *
     * @param ledIndex Index of the LED to configure.
     * @param redChannel Color value of the red channel (first channel).
     * @param greenChannel Color value of the green channel (second channel).
     * @param blueChannel Color value of the blue channel (third channel).
     */
    virtual void setLedColor(uint8_t ledIndex, uint8_t redChannel, uint8_t greenChannel, uint8_t blueChannel);

    /**
     * Set the color using four color channels of the given LED on the strip.
     *
     * @param ledIndex Index of the LED to configure.
     * @param redChannel Color value of the red channel (first channel).
     * @param greenChannel Color value of the green channel (second channel).
     * @param blueChannel Color value of the blue channel (third channel).
     * @param alphaChannel Color value of the alpha channel (fourth channel).
     */
    virtual void setLedColor(uint8_t ledIndex, uint8_t redChannel, uint8_t greenChannel, uint8_t blueChannel, uint8_t alphaChannel);

    /**
     * Set the color of the given LED on the strip.
     * The color channels are combined for this method.
     *
     * @param ledIndex Index of the LED to configure.
     * @param combinedColorValue Color value.
     */
    virtual void setLedColorCombinedChannels(uint8_t ledIndex, uint32_t combinedColorValue);
};

#endif // LEDSTRIPCONTROLLER_BASELEDSTRIPADAPTER_H
