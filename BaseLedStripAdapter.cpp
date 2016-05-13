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

#include "BaseLedStripAdapter.h"

void BaseLedStripAdapter::setRangeLedColors(uint8_t fromLedIndex, uint8_t toLedIndex, LedStripColor color) {
    // Loop through the LED range to set the values
    for(uint8_t i = fromLedIndex; i < toLedIndex; i++)
        this->setLedColor(i, color);
}

void BaseLedStripAdapter::setRangeLedColors(uint8_t fromLedIndex, uint8_t toLedIndex, uint8_t redChannel) {
    // Loop through the LED range to set the values
    for(uint8_t i = fromLedIndex; i < toLedIndex; i++)
        this->setLedColor(i, redChannel);
}

void BaseLedStripAdapter::setRangeLedColors(uint8_t fromLedIndex, uint8_t toLedIndex, uint8_t redChannel,
                                               uint8_t greenChannel) {
    // Loop through the LED range to set the values
    for(uint8_t i = fromLedIndex; i < toLedIndex; i++)
        this->setLedColor(i, redChannel, greenChannel);
}

void BaseLedStripAdapter::setRangeLedColors(uint8_t fromLedIndex, uint8_t toLedIndex, uint8_t redChannel, uint8_t greenChannel, uint8_t blueChannel) {
    // Loop through the LED range to set the values
    for(uint8_t i = fromLedIndex; i < toLedIndex; i++)
        this->setLedColor(i, redChannel, greenChannel, blueChannel);
}

void BaseLedStripAdapter::setRangeLedColors(uint8_t fromLedIndex, uint8_t toLedIndex, uint8_t redChannel,
                                               uint8_t greenChannel, uint8_t blueChannel, uint8_t alphaChannel) {
    // Loop through the LED range to set the values
    for(uint8_t i = fromLedIndex; i < toLedIndex; i++)
        this->setLedColor(i, redChannel, greenChannel, blueChannel, alphaChannel);
}

void BaseLedStripAdapter::setRangeLedColorsCombinedChannels(uint8_t fromLedIndex, uint8_t toLedIndex, uint32_t combinedColorValue) {
    // Loop through the LED range to set the values
    for(uint8_t i = fromLedIndex; i < toLedIndex; i++)
        this->setLedColorCombinedChannels(i, combinedColorValue);
}

void BaseLedStripAdapter::setAllLedColors(LedStripColor color) {
    // Set all the LEDs using the range methods
    this->setRangeLedColors(0, this->strip.numPixels(), color);
}

void BaseLedStripAdapter::setAllLedColors(uint8_t redChannel) {
    // Set all the LEDs using the range methods
    this->setRangeLedColors(0, this->strip.numPixels(), redChannel);
}

void BaseLedStripAdapter::setAllLedColors(uint8_t redChannel, uint8_t greenChannel) {
    // Set all the LEDs using the range methods
    this->setRangeLedColors(0, this->strip.numPixels(), redChannel, greenChannel);
}

void BaseLedStripAdapter::setAllLedColors(uint8_t redChannel, uint8_t greenChannel, uint8_t blueChannel) {
    // Set all the LEDs using the range methods
    this->setRangeLedColors(0, this->strip.numPixels(), redChannel, greenChannel, blueChannel);
}

void BaseLedStripAdapter::setAllLedColors(uint8_t redChannel, uint8_t greenChannel, uint8_t blueChannel,
                                             uint8_t alphaChannel) {
    // Set all the LEDs using the range methods
    this->setRangeLedColors(0, this->strip.numPixels(), redChannel, greenChannel, blueChannel, alphaChannel);
}

void BaseLedStripAdapter::setAllLedColorsCombinedChannels(uint32_t combinedColorValue) {
    // Set all the LEDs using the range methods
    this->setRangeLedColorsCombinedChannels(0, this->strip.numPixels(), combinedColorValue);
}

bool BaseLedStripAdapter::hasRedChannelSupport() {
    return this->getColorChannelCount() >= 1;
}

bool BaseLedStripAdapter::hasGreenChannelSupport() {
    return this->getColorChannelCount() >= 2;
}

bool BaseLedStripAdapter::hasBlueChannelSupport() {
    return this->getColorChannelCount() >= 3;
}

bool BaseLedStripAdapter::hasAlphaChannelSupport() {
    return this->getColorChannelCount() >= 4;
}