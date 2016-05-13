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

#include <Arduino.h>

// Include the LED strip driver headers
#include "LedStripDriver.h"



// We'll be using a LPD8806-based LED strip using the LED strip driver
typedef LedStripLPD8806 LedStrip;

/**
 * Number of LEDs on the LED strip.
 */
const uint8_t LED_STRIP_LED_COUNT = 62;

/**
 * Data pin used for the LED strip.
 */
const uint8_t LED_STRIP_PIN_DATA = 2;

/**
 * Clock pin used for the LED strip.
 */
const uint8_t LED_STRIP_PIN_CLOCK = 3;



/**
 * LED strip instance using LED strip driver.
 * Use the configured LED count, data and clock pin constants.
 */
LedStrip strip = LedStrip(LED_STRIP_LED_COUNT, LED_STRIP_PIN_DATA, LED_STRIP_PIN_CLOCK);



/**
 * Called on start.
 */
void setup() {
    // Initialize the LED Strip, must be done once before using the LED strip
    strip.init(true);
}

/**
 * Called once each loop/update.
 */
void loop() {

    /*
     * All LEDs on the LED strip can be set to a specific value.
     * The LED strip driver will output the values to the LED strip when the render method is called.
     */

    // Flash three times
    for(int i = 0; i < 3; i++) {
        // Color the LED strip
        strip.setAllLedColors(LedStripColor::red());
        strip.render();

        // Wait a little
        delay(500);

        // Clear the LED strip
        strip.clear(true);

        // Wait a little
        delay(500);
    }


    // Fade in
    LedStripAnimator::fadeIn(&strip, LedStripColor(255, 127, 0));
    delay(500);


    // Fade out
    LedStripAnimator::fadeOut(&strip, LedStripColor(255, 127, 0));
    delay(500);


    // Light up some random pixels a few times
    for(int cycle = 0; cycle < 4; cycle++) {
        // Light up some random pixels
        for(int i = 0; i < 10; i++)
            strip.setLedColor(random(0, LED_STRIP_LED_COUNT), 0, 255, 255);

        // Render the LED strip
        strip.render();

        // Wait a little
        delay(500);

        // Clear the LED strip
        strip.clear(true);

        // Wait a little
        delay(500);
    }




    /*
     * The LED strip driver provides an animator class.
     * This animator allows you to show various animations with a single line of code.
     * Animations are automatically rendered to the strip, thus an explicit call to the render method isn't required.
     */

    // Chase animations
    LedStripAnimator::chase(&strip, LedStripColor::blue(), 5);
    delay(500);
    LedStripAnimator::chase(&strip, LedStripColor(255, 0, 255), 50);
    delay(500);


    // Whipe animation
    LedStripAnimator::wipe(&strip, LedStripColor(255, 127, 0), 5);
    delay(500);


    // Rainbow animation
    LedStripAnimator::rainbow(&strip, 5);
    delay(500);


    // Fitted rainbow animation
    LedStripAnimator::rainbowFit(&strip, 5);
    delay(500);
}