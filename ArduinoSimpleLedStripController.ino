/******************************************************************************
 * Copyright (c) ArduinoSimpleLedStripController 2016. All rights reserved.   *
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

#include "LedStrip.h"
#include "LedStripColor.h"

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
 * LED strip instance.
 */
LedStrip strip = LedStrip(LED_STRIP_LED_COUNT, LED_STRIP_PIN_DATA, LED_STRIP_PIN_CLOCK);

/**
 * Called on start.
 */
void setup() {
    // Initialize the LED Strip
    strip.init(true);
}

/**
 * Called once each loop/update.
 */
void loop() {
    // Set the color of the given LED
    strip.setLedColor(1, LedStripColor(127, 127, 0));

    // Render the LED strip
    strip.render();
}