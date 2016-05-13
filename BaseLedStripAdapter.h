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
#include "LedStripColor.h"

class BaseLedStripAdapter {
public:
    /**
     * Initialize the LED strip.
     * Required before it's used.
     * This will automatically render the LED strip state once after initialization.
     */
    virtual void init() = 0;

    /**
     * Initialize the LED strip.
     * Required before it's used.
     *
     * @param render True to automatically render once after initialization, false if not.
     */
    virtual void init(bool render) = 0;

    /**
     * Render the state of the LED strip to the physical hardware.
     */
    virtual void render() = 0;

    /**
     * Get the color of the given LED on the strip.
     *
     * @param ledIndex Index of the LED to configure.
     *
     * @return LED color.
     */
    virtual LedStripColor getLedColor(uint8_t ledIndex) = 0;

    /**
     * Set the color of the given LED on the strip.
     *
     * @param ledIndex Index of the LED to configure.
     * @param color LED color.
     */
    virtual void setLedColor(uint8_t ledIndex, LedStripColor color) = 0;

    /**
     * Set the color using one color channel of the given LED on the strip.
     *
     * @param ledIndex Index of the LED to configure.
     * @param redChannel Color value of the red channel (first channel).
     */
    virtual void setLedColor(uint8_t ledIndex, uint8_t redChannel) = 0;

    /**
     * Set the color using two color channels of the given LED on the strip.
     *
     * @param ledIndex Index of the LED to configure.
     * @param redChannel Color value of the red channel (first channel).
     * @param greenChannel Color value of the green channel (second channel).
     */
    virtual void setLedColor(uint8_t ledIndex, uint8_t redChannel, uint8_t greenChannel) = 0;

    /**
     * Set the color using three color channels of the given LED on the strip.
     *
     * @param ledIndex Index of the LED to configure.
     * @param redChannel Color value of the red channel (first channel).
     * @param greenChannel Color value of the green channel (second channel).
     * @param blueChannel Color value of the blue channel (third channel).
     */
    virtual void setLedColor(uint8_t ledIndex, uint8_t redChannel, uint8_t greenChannel, uint8_t blueChannel) = 0;

    /**
     * Set the color using four color channels of the given LED on the strip.
     *
     * @param ledIndex Index of the LED to configure.
     * @param redChannel Color value of the red channel (first channel).
     * @param greenChannel Color value of the green channel (second channel).
     * @param blueChannel Color value of the blue channel (third channel).
     * @param alphaChannel Color value of the alpha channel (fourth channel).
     */
    virtual void setLedColor(uint8_t ledIndex, uint8_t redChannel, uint8_t greenChannel, uint8_t blueChannel, uint8_t alphaChannel) = 0;

    /**
     * Get the color of the given LED on the strip.
     * The color channels are combined for this method.
     *
     * @return Combined color channels.
     */
    virtual uint32_t getLedColorCombinedChannels(uint8_t ledIndex) = 0;

    /**
     * Set the color of the given LED on the strip.
     * The color channels are combined for this method.
     *
     * @param ledIndex Index of the LED to configure.
     * @param combinedColorValue Color value.
     */
    virtual void setLedColorCombinedChannels(uint8_t ledIndex, uint32_t combinedColorValue) = 0;

    /**
     * Set the color of the LEDs in the given range on the strip.
     *
     * @param fromLedIndex From LED index.
     * @param toLedIndex To LED index. (excluded)
     * @param color LED color.
     */
    virtual void setRangeLedColors(uint8_t fromLedIndex, uint8_t toLedIndex, LedStripColor color) = 0;

    /**
     * Set the color using one color channel of the LEDs in the given range on the strip.
     *
     * @param fromLedIndex From LED index.
     * @param toLedIndex To LED index. (excluded)
     * @param redChannel Color value of the red channel (first channel).
     */
    virtual void setRangeLedColors(uint8_t fromLedIndex, uint8_t toLedIndex, uint8_t redChannel) = 0;

    /**
     * Set the color using two color channels of the LEDs in the given range on the strip.
     *
     * @param fromLedIndex From LED index.
     * @param toLedIndex To LED index. (excluded)
     * @param redChannel Color value of the red channel (first channel).
     * @param greenChannel Color value of the green channel (second channel).
     */
    virtual void setRangeLedColors(uint8_t fromLedIndex, uint8_t toLedIndex, uint8_t redChannel,
                                   uint8_t greenChannel) = 0;

    /**
     * Set the color using three color channels of the LEDs in the given range on the strip.
     *
     * @param fromLedIndex From LED index.
     * @param toLedIndex To LED index. (excluded)
     * @param redChannel Color value of the red channel (first channel).
     * @param greenChannel Color value of the green channel (second channel).
     * @param blueChannel Color value of the blue channel (third channel).
     */
    virtual void setRangeLedColors(uint8_t fromLedIndex, uint8_t toLedIndex, uint8_t redChannel,
                                   uint8_t greenChannel, uint8_t blueChannel) = 0;

    /**
     * Set the color using four color channels of the LEDs in the given range on the strip.
     *
     * @param fromLedIndex From LED index.
     * @param toLedIndex To LED index. (excluded)
     * @param redChannel Color value of the red channel (first channel).
     * @param greenChannel Color value of the green channel (second channel).
     * @param blueChannel Color value of the blue channel (third channel).
     * @param alphaChannel Color value of the alpha channel (fourth channel).
     */
    virtual void setRangeLedColors(uint8_t fromLedIndex, uint8_t toLedIndex, uint8_t redChannel, uint8_t greenChannel,
                                   uint8_t blueChannel, uint8_t alphaChannel) = 0;

    /**
     * Set the color of the LEDs in the given range on the strip.
     * The color channels are combined for this method.
     *
     * @param fromLedIndex From LED index.
     * @param toLedIndex To LED index. (excluded)
     * @param combinedColorValue Color value.
     */
    virtual void setRangeLedColorsCombinedChannels(uint8_t fromLedIndex, uint8_t toLedIndex,
                                                   uint32_t combinedColorValue) = 0;

    /**
     * Set the color of all the LEDs on the strip.
     *
     * @param color LED color.
     */
    virtual void setAllLedColors(LedStripColor color) = 0;

    /**
     * Set the color using one color channel of all the LEDs on the strip.
     *
     * @param redChannel Color value of the red channel (first channel).
     */
    virtual void setAllLedColors(uint8_t redChannel) = 0;

    /**
     * Set the color using two color channels of all the LEDs on the strip.
     *
     * @param redChannel Color value of the red channel (first channel).
     * @param greenChannel Color value of the green channel (second channel).
     */
    virtual void setAllLedColors(uint8_t redChannel, uint8_t greenChannel) = 0;

    /**
     * Set the color using three color channels of all the LEDs on the strip.
     *
     * @param redChannel Color value of the red channel (first channel).
     * @param greenChannel Color value of the green channel (second channel).
     * @param blueChannel Color value of the blue channel (third channel).
     */
    virtual void setAllLedColors(uint8_t redChannel, uint8_t greenChannel, uint8_t blueChannel) = 0;

    /**
     * Set the color using four color channels of all the LEDs on the strip.
     *
     * @param redChannel Color value of the red channel (first channel).
     * @param greenChannel Color value of the green channel (second channel).
     * @param blueChannel Color value of the blue channel (third channel).
     * @param alphaChannel Color value of the alpha channel (fourth channel).
     */
    virtual void setAllLedColors(uint8_t redChannel, uint8_t greenChannel, uint8_t blueChannel,
                                 uint8_t alphaChannel) = 0;

    /**
     * Set the color of all the LEDs on the strip.
     * The color channels are combined for this method.
     *
     * @param combinedColorValue Color value.
     */
    virtual void setAllLedColorsCombinedChannels(uint32_t combinedColorValue) = 0;

    /**
     * Get the number of color channels this LED strip has.
     */
    virtual uint8_t getColorChannelCount() = 0;

    /**
     * Get the maximum color value for each color channel on this LED strip.
     */
    virtual uint8_t getColorValueMax() = 0;

    /**
     * Check whether this LED strip has support for the red color channel.
     *
     * @return True if this LED strip has support, false if not.
     */
    bool hasRedChannelSupport();

    /**
     * Check whether this LED strip has support for the green color channel.
     *
     * @return True if this LED strip has support, false if not.
     */
    bool hasGreenChannelSupport();

    /**
     * Check whether this LED strip has support for the blue color channel.
     *
     * @return True if this LED strip has support, false if not.
     */
    bool hasBlueChannelSupport();

    /**
     * Check whether this LED strip has support for the alpha channel.
     *
     * @return True if this LED strip has support, false if not.
     */
    bool hasAlphaChannelSupport();
};

#endif // LEDSTRIPCONTROLLER_BASELEDSTRIPADAPTER_H
