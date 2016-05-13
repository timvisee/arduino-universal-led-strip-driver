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
//    delete &this->strip;
}

void LedStripAdapterLPD8806::init() {
    // Initialize/begin the LED strip
    this->strip.begin();
}

void LedStripAdapterLPD8806::init(bool render) {
    // Initialize/begin the LED strip
    this->strip.begin();

    // Render the LED strip
    if(render)
        this->render();
}

void LedStripAdapterLPD8806::render() {
    // Render the LED strip
    this->strip.show();
}

LedStripColor LedStripAdapterLPD8806::getLedColor(uint8_t ledIndex) {
    return LedStripColor::fromCombinedChannels(this->getLedColorCombinedChannels(ledIndex));
}

void LedStripAdapterLPD8806::setLedColor(uint8_t ledIndex, LedStripColor color) {
    // Decapsulate the Color object, and set the LEDs color
    this->setLedColorCombinedChannels(ledIndex, color.getCombinedChannels());
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
    this->strip.setPixelColor(ledIndex, redChannel / 2, greenChannel / 2, blueChannel / 2);
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
    return ((uint32_t) (rawColor & (uint32_t) 0xFF << 8)<<  24) |
           ((uint32_t) (rawColor & (uint32_t) 0xFF << 16) << 16) |
           ((uint32_t) (rawColor & (uint32_t) 0xFF << 0) << 8) |
           LED_STRIP_COLOR_VALUE_MAX & 0xFF;
}

void LedStripAdapterLPD8806::setLedColorCombinedChannels(uint8_t ledIndex, uint32_t combinedColorValue) {
    // Translate and set the LED strip color to the hardware color
    this->strip.setPixelColor(ledIndex,
            ((uint32_t) ((combinedColorValue & (uint32_t) 0xFF << 24) / 2 >> 24) | 0x80) << 8 |
            ((uint32_t) ((combinedColorValue & (uint32_t) 0xFF << 16) / 2 >> 16) | 0x80) << 16 |
            ((uint32_t) ((combinedColorValue & (uint32_t) 0xFF << 8) / 2 >> 8) | 0x80) << 0
    );
}

void LedStripAdapterLPD8806::setRangeLedColors(uint8_t fromLedIndex, uint8_t toLedIndex, LedStripColor color) {
    // Loop through the LED range to set the values
    for(uint8_t i = fromLedIndex; i < toLedIndex; i++)
        this->setLedColor(i, color);
}

void LedStripAdapterLPD8806::setRangeLedColors(uint8_t fromLedIndex, uint8_t toLedIndex, uint8_t redChannel) {
    // Loop through the LED range to set the values
    for(uint8_t i = fromLedIndex; i < toLedIndex; i++)
        this->setLedColor(i, redChannel);
}

void LedStripAdapterLPD8806::setRangeLedColors(uint8_t fromLedIndex, uint8_t toLedIndex, uint8_t redChannel,
                                               uint8_t greenChannel) {
    // Loop through the LED range to set the values
    for(uint8_t i = fromLedIndex; i < toLedIndex; i++)
        this->setLedColor(i, redChannel, greenChannel);
}

void LedStripAdapterLPD8806::setRangeLedColors(uint8_t fromLedIndex, uint8_t toLedIndex, uint8_t redChannel, uint8_t greenChannel, uint8_t blueChannel) {
    // Loop through the LED range to set the values
    for(uint8_t i = fromLedIndex; i < toLedIndex; i++)
        this->setLedColor(i, redChannel, greenChannel, blueChannel);
}

void LedStripAdapterLPD8806::setRangeLedColors(uint8_t fromLedIndex, uint8_t toLedIndex, uint8_t redChannel,
                                               uint8_t greenChannel, uint8_t blueChannel, uint8_t alphaChannel) {
    // Loop through the LED range to set the values
    for(uint8_t i = fromLedIndex; i < toLedIndex; i++)
        this->setLedColor(i, redChannel, greenChannel, blueChannel, alphaChannel);
}

void LedStripAdapterLPD8806::setRangeLedColorsCombinedChannels(uint8_t fromLedIndex, uint8_t toLedIndex, uint32_t combinedColorValue) {
    // Loop through the LED range to set the values
    for(uint8_t i = fromLedIndex; i < toLedIndex; i++)
        this->setLedColorCombinedChannels(i, combinedColorValue);
}

void LedStripAdapterLPD8806::setAllLedColors(LedStripColor color) {
    // Set all the LEDs using the range methods
    this->setRangeLedColors(0, this->strip.numPixels(), color);
}

void LedStripAdapterLPD8806::setAllLedColors(uint8_t redChannel) {
    // Set all the LEDs using the range methods
    this->setRangeLedColors(0, this->strip.numPixels(), redChannel);
}

void LedStripAdapterLPD8806::setAllLedColors(uint8_t redChannel, uint8_t greenChannel) {
    // Set all the LEDs using the range methods
    this->setRangeLedColors(0, this->strip.numPixels(), redChannel, greenChannel);
}

void LedStripAdapterLPD8806::setAllLedColors(uint8_t redChannel, uint8_t greenChannel, uint8_t blueChannel) {
    // Set all the LEDs using the range methods
    this->setRangeLedColors(0, this->strip.numPixels(), redChannel, greenChannel, blueChannel);
}

void LedStripAdapterLPD8806::setAllLedColors(uint8_t redChannel, uint8_t greenChannel, uint8_t blueChannel,
                                             uint8_t alphaChannel) {
    // Set all the LEDs using the range methods
    this->setRangeLedColors(0, this->strip.numPixels(), redChannel, greenChannel, blueChannel, alphaChannel);
}

void LedStripAdapterLPD8806::setAllLedColorsCombinedChannels(uint32_t combinedColorValue) {
    // Set all the LEDs using the range methods
    this->setRangeLedColorsCombinedChannels(0, this->strip.numPixels(), combinedColorValue);
}

uint8_t LedStripAdapterLPD8806::getColorChannelCount() {
    return LPD8806_COLOR_CHANNEL_COUNT;
}

uint8_t LedStripAdapterLPD8806::getColorValueMax() {
    return LPD8806_COLOR_VALUE_MAX;
}