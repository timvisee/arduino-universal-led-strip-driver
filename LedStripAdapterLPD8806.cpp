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

#include "LedStripAdapterLPD8806.h"

LedStripAdapterLPD8806::LedStripAdapterLPD8806(uint8_t ledCount, uint8_t pinData, uint8_t pinClock) {
    // Initialize the LED strip
    strip = LPD8806(ledCount, pinData, pinClock);
}

LedStripAdapterLPD8806::~LedStripAdapterLPD8806() {
    // Explicitly delete the strip field
    delete this->strip;
}

LedStripColor LedStripAdapterLPD8806::getLedColor(uint8_t ledIndex) {
    return LedStripColor::fromCombinedChannels(this->getLedColorCombinedChannels(ledIndex));
}

void LedStripAdapterLPD8806::setLedColor(uint8_t ledIndex, LedStripColor color) {
    // Decapsulate the Color object, and set the LEDs color
    this->setLedColor(ledIndex, color.getCombinedChannels());
}

void LedStripAdapterLPD8806::setLedColor(uint8_t ledIndex, uint8_t redChannel) {
    // Get the color of the LED
    LedStripColor ledColor = this->getLedColor(ledIndex);

    // Set the red channel
    ledColor.setRed(redChannel);

    // Update the led color
    this->setLedColor(ledIndex, ledColor);
}

void LedStripAdapterLPD8806::setLedColor(uint8_t ledIndex, uint8_t redChannel, uint8_t greenChannel) {
    // Get the color of the LED
    LedStripColor ledColor = this->getLedColor(ledIndex);

    // Set the red and green channel
    ledColor.setRed(redChannel);
    ledColor.setGreen(greenChannel);

    // Update the led color
    this->setLedColor(ledIndex, ledColor);
}

void LedStripAdapterLPD8806::setLedColor(uint8_t ledIndex,
                                         uint8_t redChannel, uint8_t greenChannel, uint8_t blueChannel) {
    this->strip.setPixelColor(ledIndex, redChannel, greenChannel, blueChannel);
}

void LedStripAdapterLPD8806::setLedColor(uint8_t ledIndex,
                                         uint8_t redChannel, uint8_t greenChannel,
                                         uint8_t blueChannel, uint8_t alphaChannel) {
    // Set the color without the alpha channel, since this channel isn't supported
    this->setLedColor(ledIndex, redChannel, greenChannel, blueChannel);
}

uint32_t LedStripAdapterLPD8806::getLedColorCombinedChannels(uint8_t ledIndex) {
    // Get the raw color value
    uint32_t rawColor = this->strip.getPixelColor(ledIndex);

    // Translate the color to the LED strip color space, and return
    return ((uint32_t) ((rawColor & ((uint32_t) 0xFF) << 8)) <<  24) |
           ((uint32_t) ((rawColor & ((uint32_t) 0xFF) << 16)) << 16) |
           ((uint32_t) ((rawColor & ((uint32_t) 0xFF) << 0)) << 8) |
           LED_STRIP_COLOR_VALUE_MAX & 0xFF;
}

void LedStripAdapterLPD8806::setLedColorCombinedChannels(uint8_t ledIndex, uint32_t combinedColorValue) {
    // Translate and set the LED strip color to the hardware color
    this->strip.setPixelColor(ledIndex,
            ((uint32_t) ((combinedColorValue & (((uint32_t) 0xFF) << 24)) | 0x80) <<  8) |
            ((uint32_t) ((combinedColorValue & (((uint32_t) 0xFF) << 16)) | 0x80) << 16) |
            (uint32_t) ((combinedColorValue & (((uint32_t) 0xFF) << 8)) | 0x80)
    );
}

uint8_t LedStripAdapterLPD8806::getColorChannelCount() {
    return LPD8806_COLOR_CHANNEL_COUNT;
}

uint8_t LedStripAdapterLPD8806::getColorValueMax() {
    return LPD8806_COLOR_VALUE_MAX;
}