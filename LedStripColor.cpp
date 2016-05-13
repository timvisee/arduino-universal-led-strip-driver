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

#include "LedStripColor.h"

LedStripColor::LedStripColor() : LedStripColor(0) { }

LedStripColor::LedStripColor(uint8_t redChannel) : LedStripColor(redChannel, 0) { }

LedStripColor::LedStripColor(uint8_t redChannel, uint8_t greenChannel) : LedStripColor(redChannel, greenChannel, 0) { }

LedStripColor::LedStripColor(uint8_t redChannel, uint8_t greenChannel, uint8_t blueChannel)
        : LedStripColor(redChannel, greenChannel, blueChannel, (uint8_t) LED_STRIP_COLOR_VALUE_MAX) { }

LedStripColor::LedStripColor(uint8_t redChannel, uint8_t greenChannel, uint8_t blueChannel, uint8_t alphaChannel) {
    this->redChannel = redChannel;
    this->greenChannel = greenChannel;
    this->blueChannel = blueChannel;
    this->alphaChannel = alphaChannel;
}

LedStripColor::~LedStripColor() { }

LedStripColor LedStripColor::fromCombinedChannels(uint32_t combined) {
    // Construct a LedStripColor object
    LedStripColor color = LedStripColor();

    // Set the combined values
    color.setCombinedChannels(combined);

    // Return the object
    return color;
}

LedStripColor LedStripColor::fromSmallWheel(uint16_t position) {
    return LedStripColor::fromWheel(position * 2);
}

LedStripColor LedStripColor::fromWheel(uint16_t position) {
    // Define the color variables
    uint8_t r = 0, g = 0, b = 0;

    // Cap the position
    position %= LED_STRIP_COLOR_WHEEL_SIZE;

    // Determine the colors
    if(position >= 0 && position < LED_STRIP_COLOR_VALUE_SIZE) {
        // Red down, green up
        r = LED_STRIP_COLOR_VALUE_MAX - position % LED_STRIP_COLOR_VALUE_SIZE;
        g = position % LED_STRIP_COLOR_VALUE_SIZE;

    } else if(position >= LED_STRIP_COLOR_VALUE_SIZE && position < LED_STRIP_COLOR_VALUE_SIZE * 2) {
        // Green down, blue up
        g = LED_STRIP_COLOR_VALUE_MAX - position % LED_STRIP_COLOR_VALUE_SIZE;
        b = position % LED_STRIP_COLOR_VALUE_SIZE;

    } else if(position >= LED_STRIP_COLOR_VALUE_SIZE * 2 && position < LED_STRIP_COLOR_VALUE_SIZE * 3) {
        // Blue down, red up
        b = LED_STRIP_COLOR_VALUE_MAX - position % LED_STRIP_COLOR_VALUE_SIZE;
        r = position % LED_STRIP_COLOR_VALUE_SIZE;
    }

    // Create and return the LED strip color instance
    return LedStripColor(r, g, b);
}

LedStripColor LedStripColor::black() {
    return LedStripColor(0, 0, 0);
}

LedStripColor LedStripColor::white() {
    return LedStripColor(LED_STRIP_COLOR_VALUE_MAX, LED_STRIP_COLOR_VALUE_MAX, LED_STRIP_COLOR_VALUE_MAX);
}

LedStripColor LedStripColor::red() {
    return LedStripColor(LED_STRIP_COLOR_VALUE_MAX, 0, 0);
}

LedStripColor LedStripColor::green() {
    return LedStripColor(0, LED_STRIP_COLOR_VALUE_MAX, 0);
}

LedStripColor LedStripColor::blue() {
    return LedStripColor(0, 0, LED_STRIP_COLOR_VALUE_MAX);
}

uint8_t LedStripColor::getRed() {
    return this->redChannel;
}

void LedStripColor::setRed(uint8_t redChannel) {
    this->redChannel = redChannel;
}

uint8_t LedStripColor::getGreen() {
    return this->greenChannel;
}

void LedStripColor::setGreen(uint8_t greenChannel) {
    this->greenChannel = greenChannel;
}

uint8_t LedStripColor::getBlue() {
    return this->blueChannel;
}

void LedStripColor::setBlue(uint8_t blueChannel) {
    this->blueChannel = blueChannel;
}

uint8_t LedStripColor::getAlpha() {
    return this->alphaChannel;
}

void LedStripColor::setAlpha(uint8_t alphaChannel) {
    this->alphaChannel = alphaChannel;
}

uint32_t LedStripColor::getCombinedChannels() {
    // Determine the combined color channels value based on the color channels
    return ((uint32_t) (this->redChannel & 0xFF) << 24) |
           ((uint32_t) (this->greenChannel & 0xFF) << 16) |
           ((uint32_t) (this->blueChannel & 0xFF) << 8) |
           (uint32_t) (this->blueChannel & 0xFF);
}

uint32_t LedStripColor::setCombinedChannels(uint32_t combined) {
    // Fetch the color channel values from the combined value
    this->redChannel = (uint8_t) (combined & (0xFF << 24));
    this->greenChannel = (uint8_t) (combined & (0xFF << 16));
    this->blueChannel = (uint8_t) (combined & (0xFF << 8));
    this->alphaChannel = (uint8_t) (combined & 0xFF);
}