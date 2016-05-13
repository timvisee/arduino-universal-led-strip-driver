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

#ifndef LEDSTRIPCONTROLLER_LEDSTRIPBASE_H
#define LEDSTRIPCONTROLLER_LEDSTRIPBASE_H

#include "LedStripAdapterBase.h"

/**
 * LedStrip base class.
 * This class represents the base of a physical LED strip, and provides an interface to control the strip.
 *
 * @author Tim Visee
 * @website http://timvisee.com/
 * @version 1.1
 */
class BaseLedStrip {
private:
    /**
     * Number of LEDs this LED strip contains.
     */
    uint8_t ledCount;

    /**
     * LED strip adapter for the used LED strip type.
     */
    BaseLedStripAdapter* adapter;

protected:
    /**
     * Constructor.
     * The LED strip adapter must be specified manually before this LED strip instance is used.
     *
     * @param ledCount Number of LEDs.
     */
    BaseLedStrip(uint8_t ledCount);

    /**
     * Constructor.
     *
     * @param ledCount Number of LEDs.
     * @param adapter LED strip adapter for the used LED strip type.
     */
    BaseLedStrip(uint8_t ledCount, BaseLedStripAdapter* adapter);

    /**
     * Destructor.
     */
    ~BaseLedStrip();

public:
    /**
     * Initialize the LED strip adapter.
     * Required before the LED strip is used.
     */
    virtual void init() = 0;

    /**
     * Render the state of the LED strip to the physical hardware.
     */
    virtual void render() = 0;

    /**
     * Get the number of LEDs this LED strip has.
     *
     * @return LED count.
     */
    uint8_t getLedCount();

    /**
     * Set and update the number of LEDs this LED strip has.
     *
     * @param ledCount LED count.
     */
    void setLedCount(uint8_t ledCount);

    /**
     * Get the LED strip adapter instance.
     *
     * @return LED strip adapter.
     */
    BaseLedStripAdapter* getAdapter();

protected:
    /**
     * Set the LED strip adapter instance.
     *
     * @param adapter LED strip adapter.
     */
    void setAdapter(BaseLedStripAdapter* adapter);

public:
    /**
     * Get the color of the given LED on the strip.
     *
     * @param ledIndex Index of the LED to configure.
     *
     * @return LED color.
     */
    LedStripColor getLedColor(uint8_t ledIndex);

    /**
     * Set the color of the given LED on the strip.
     *
     * @param ledIndex Index of the LED to configure.
     * @param color LED color.
     */
    void setLedColor(uint8_t ledIndex, LedStripColor color);

    /**
     * Set the color using one color channel of the given LED on the strip.
     *
     * @param ledIndex Index of the LED to configure.
     * @param redChannel Color value of the red channel (first channel).
     */
    void setLedColor(uint8_t ledIndex, uint8_t redChannel);

    /**
     * Set the color using two color channels of the given LED on the strip.
     *
     * @param ledIndex Index of the LED to configure.
     * @param redChannel Color value of the red channel (first channel).
     * @param greenChannel Color value of the green channel (second channel).
     */
    void setLedColor(uint8_t ledIndex, uint8_t redChannel, uint8_t greenChannel);

    /**
     * Set the color using three color channels of the given LED on the strip.
     *
     * @param ledIndex Index of the LED to configure.
     * @param redChannel Color value of the red channel (first channel).
     * @param greenChannel Color value of the green channel (second channel).
     * @param blueChannel Color value of the blue channel (third channel).
     */
    void setLedColor(uint8_t ledIndex, uint8_t redChannel, uint8_t greenChannel, uint8_t blueChannel);

    /**
     * Set the color using four color channels of the given LED on the strip.
     *
     * @param ledIndex Index of the LED to configure.
     * @param redChannel Color value of the red channel (first channel).
     * @param greenChannel Color value of the green channel (second channel).
     * @param blueChannel Color value of the blue channel (third channel).
     * @param alphaChannel Color value of the alpha channel (fourth channel).
     */
    void setLedColor(uint8_t ledIndex, uint8_t redChannel, uint8_t greenChannel, uint8_t blueChannel,
                     uint8_t alphaChannel);

    /**
     * Set the color of the LEDs in the given range on the strip.
     *
     * @param fromLedIndex From LED index.
     * @param toLedIndex To LED index. (excluded)
     * @param color LED color.
     */
    void setRangeLedColors(uint8_t fromLedIndex, uint8_t toLedIndex, LedStripColor color);

    /**
     * Set the color using one color channel of the LEDs in the given range on the strip.
     *
     * @param fromLedIndex From LED index.
     * @param toLedIndex To LED index. (excluded)
     * @param redChannel Color value of the red channel (first channel).
     */
    void setRangeLedColors(uint8_t fromLedIndex, uint8_t toLedIndex, uint8_t redChannel);

    /**
     * Set the color using two color channels of the LEDs in the given range on the strip.
     *
     * @param fromLedIndex From LED index.
     * @param toLedIndex To LED index. (excluded)
     * @param redChannel Color value of the red channel (first channel).
     * @param greenChannel Color value of the green channel (second channel).
     */
    void setRangeLedColors(uint8_t fromLedIndex, uint8_t toLedIndex, uint8_t redChannel,
                                   uint8_t greenChannel);

    /**
     * Set the color using three color channels of the LEDs in the given range on the strip.
     *
     * @param fromLedIndex From LED index.
     * @param toLedIndex To LED index. (excluded)
     * @param redChannel Color value of the red channel (first channel).
     * @param greenChannel Color value of the green channel (second channel).
     * @param blueChannel Color value of the blue channel (third channel).
     */
    void setRangeLedColors(uint8_t fromLedIndex, uint8_t toLedIndex, uint8_t redChannel,
                                   uint8_t greenChannel, uint8_t blueChannel);

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
    void setRangeLedColors(uint8_t fromLedIndex, uint8_t toLedIndex, uint8_t redChannel,
                                   uint8_t greenChannel, uint8_t blueChannel, uint8_t alphaChannel);

    /**
     * Set the color of all the LEDs on the strip.
     *
     * @param color LED color.
     */
    void setAllLedColors(LedStripColor color);

    /**
     * Set the color using one color channel of all the LEDs on the strip.
     *
     * @param redChannel Color value of the red channel (first channel).
     */
    void setAllLedColors(uint8_t redChannel);

    /**
     * Set the color using two color channels of all the LEDs on the strip.
     *
     * @param redChannel Color value of the red channel (first channel).
     * @param greenChannel Color value of the green channel (second channel).
     */
    void setAllLedColors(uint8_t redChannel, uint8_t greenChannel);

    /**
     * Set the color using three color channels of all the LEDs on the strip.
     *
     * @param redChannel Color value of the red channel (first channel).
     * @param greenChannel Color value of the green channel (second channel).
     * @param blueChannel Color value of the blue channel (third channel).
     */
    void setAllLedColors(uint8_t redChannel, uint8_t greenChannel, uint8_t blueChannel);

    /**
     * Set the color using four color channels of all the LEDs on the strip.
     *
     * @param redChannel Color value of the red channel (first channel).
     * @param greenChannel Color value of the green channel (second channel).
     * @param blueChannel Color value of the blue channel (third channel).
     * @param alphaChannel Color value of the alpha channel (fourth channel).
     */
    void setAllLedColors(uint8_t redChannel, uint8_t greenChannel, uint8_t blueChannel,
                                 uint8_t alphaChannel);
};

#endif // LEDSTRIPCONTROLLER_LEDSTRIPBASE_H
