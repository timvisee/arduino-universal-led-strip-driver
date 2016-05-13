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

class LedStripAnimator {
public:
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
    static void colorWipe(LedStripBase* ledStrip, LedStripColor color, unsigned long wait);
};

#endif // LEDSTRIPDRIVER_LEDSTRIPANIMATOR_H
