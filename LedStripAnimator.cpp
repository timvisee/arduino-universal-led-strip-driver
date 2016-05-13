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

#include "LedStripAnimator.h"

void LedStripAnimator::rainbow(LedStripBase *ledStrip) {
    LedStripAnimator::rainbow(ledStrip, 0);
}

void LedStripAnimator::rainbow(LedStripBase *ledStrip, unsigned long wait) {
    // Define the for-loop index variables
    uint16_t ledIndex, iteration;

    // Loop through all the rainbow iterations
    for(iteration = 0; iteration < LED_STRIP_COLOR_WHEEL_SIZE; iteration += 2) {
        // Color all the LEDs
        for(ledIndex = 0; ledIndex < (*ledStrip).getLedCount(); ledIndex++)
            (*ledStrip).setLedColor(ledIndex, LedStripColor::fromWheel((ledIndex + iteration)));

        // Render the LED strip
        (*ledStrip).render();

        // Wait for the given amount of time
        delay(wait);
    }
}

void LedStripAnimator::rainbowFit(LedStripBase *ledStrip) {
    LedStripAnimator::rainbowFit(ledStrip, 0);
}

void LedStripAnimator::rainbowFit(LedStripBase *ledStrip, unsigned long wait) {
    // Define the for-loop index variables
    uint16_t ledIndex, iteration;

    // Loop through all the rainbow iterations
    for(iteration = 0; iteration < LED_STRIP_COLOR_WHEEL_SIZE; iteration += 2) {
        // Color all the LEDs
        for(ledIndex = 0; ledIndex < (*ledStrip).getLedCount(); ledIndex++)
            (*ledStrip).setLedColor(ledIndex, LedStripColor::fromWheel(
                    (ledIndex * LED_STRIP_COLOR_WHEEL_SIZE / (*ledStrip).getLedCount()) + iteration
            ));

        // Render the LED strip
        (*ledStrip).render();

        // Wait for the given amount of time
        delay(wait);
    }
}

void LedStripAnimator::colorWipe(LedStripBase *ledStrip, LedStripColor color, unsigned long wait) {
    for(uint16_t ledIndex=0; ledIndex < (*ledStrip).getLedCount(); ledIndex++) {
        // Set the color of the current LED
        (*ledStrip).setLedColor(ledIndex, color);

        // Render the LED strip
        (*ledStrip).render();

        // Wait for the given amount of time
        delay(wait);
    }
}
