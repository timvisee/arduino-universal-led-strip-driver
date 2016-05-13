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

#ifndef LEDSTRIPDRIVER_LEDSTRIPANIMATOR_H
#define LEDSTRIPDRIVER_LEDSTRIPANIMATOR_H

#include <Arduino.h>

#include "LedStripBase.h"

/**
 * LED strip animator helper class.
 * This class provides methods to easily animate a LED strip.
 *
 * @author Tim Visee
 * @website http://timvisee.com/
 */
class LedStripAnimator {
public:
    /**
     * Fade in.
     *
     * @param ledStrip Led strip instance pointer.
     * @param color Color to fade.
     */
    static void fadeIn(LedStripBase* ledStrip, LedStripColor color);

    /**
     * Fade out.
     *
     * @param ledStrip Led strip instance pointer.
     * @param color Color to fade.
     */
    static void fadeOut(LedStripBase* ledStrip, LedStripColor color);

    /**
     * Fade.
     *
     * @param ledStrip Led strip instance pointer.
     * @param color Color to fade.
     */
    static void fade(LedStripBase* ledStrip, uint8_t from, uint8_t to, LedStripColor color);

    /**
     * Fade.
     *
     * @param ledStrip Led strip instance pointer.
     * @param color Color to fade.
     * @param wait Cycle delay in milliseconds.
     */
    static void fade(LedStripBase* ledStrip, uint8_t from, uint8_t to, LedStripColor color, unsigned long wait);

    /**
     * Rainbow animation.
     *
     * @param ledStrip Led strip instance pointer.
     */
    static void rainbow(LedStripBase* ledStrip);

    /**
     * Rainbow animation.
     *
     * @param ledStrip Led strip instance pointer.
     * @param wait Number of milliseconds to wait between each rainbow cycle.
     */
    static void rainbow(LedStripBase* ledStrip, unsigned long wait);

    /**
     * @param ledStrip Led strip instance pointer.
     * Rainbow animation that fits the whole LED strip.
     */
    static void rainbowFit(LedStripBase* ledStrip);

    /**
     * Rainbow animation that fits the whole LED strip.
     *
     * @param ledStrip Led strip instance pointer.
     * @param wait Number of milliseconds to wait between each rainbow cycle.
     */
    static void rainbowFit(LedStripBase* ledStrip, unsigned long wait);

    /**
     * Color wiping animation which fills the LED strip progressively.
     *
     * @param ledStrip Led strip instance pointer.
     * @param color Color to fill up with.
     * @param wait Number of milliseconds to wait between each cycle.
     */
    static void wipe(LedStripBase *ledStrip, LedStripColor color, unsigned long wait);

    /**
     * Color chasing animation which chases one dot down the LED strip.
     *
     * @param ledStrip Led strip instance pointer.
     * @param color Color to fill up with.
     * @param wait Number of milliseconds to wait between each cycle.
     */
    static void chase(LedStripBase *ledStrip, LedStripColor color, unsigned long wait);

    /**
     * Theater styled chasing animation which chases one dot down the LED strip.
     *
     * @param ledStrip Led strip instance pointer.
     * @param color Color to fill up with.
     * @param cycles Number of cycles.
     * @param wait Number of milliseconds to wait between each cycle.
     */
    static void theaterChase(LedStripBase* ledStrip, LedStripColor color, uint16_t cycles, unsigned long wait);

    /**
     * Theater styled chasing animation with a rainbow which chases one dot down the LED strip.
     *
     * @param ledStrip Led strip instance pointer.
     * @param wait Number of milliseconds to wait between each cycle.
     */
    static void theaterChaseRainbow(LedStripBase* ledStrip, unsigned long wait);

    /**
     * Theater styled chasing animation with a rainbow which chases one dot down the LED strip.
     *
     * @param ledStrip Led strip instance pointer.
     * @param cycles Number of cycles.
     * @param wait Number of milliseconds to wait between each cycle.
     */
    static void theaterChaseRainbow(LedStripBase* ledStrip, uint16_t cycles, unsigned long wait);
};

#endif // LEDSTRIPDRIVER_LEDSTRIPANIMATOR_H
