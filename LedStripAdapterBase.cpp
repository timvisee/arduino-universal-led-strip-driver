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

#include "LedStripAdapterBase.h"

void LedStripAdapterBase::setRangeLedColors(uint16_t fromLedIndex, uint16_t toLedIndex, LedStripColor color) {
    // Loop through the LED range to set the values
    for(uint16_t i = fromLedIndex; i < toLedIndex; i++)
        this->setLedColor(i, color);
}

void LedStripAdapterBase::setRangeLedColors(uint16_t fromLedIndex, uint16_t toLedIndex, uint8_t redChannel) {
    // Loop through the LED range to set the values
    for(uint16_t i = fromLedIndex; i < toLedIndex; i++)
        this->setLedColor(i, redChannel);
}

void LedStripAdapterBase::setRangeLedColors(uint16_t fromLedIndex, uint16_t toLedIndex, uint8_t redChannel,
                                               uint8_t greenChannel) {
    // Loop through the LED range to set the values
    for(uint16_t i = fromLedIndex; i < toLedIndex; i++)
        this->setLedColor(i, redChannel, greenChannel);
}

void LedStripAdapterBase::setRangeLedColors(uint16_t fromLedIndex, uint16_t toLedIndex, uint8_t redChannel, uint8_t greenChannel, uint8_t blueChannel) {
    // Loop through the LED range to set the values
    for(uint16_t i = fromLedIndex; i < toLedIndex; i++)
        this->setLedColor(i, redChannel, greenChannel, blueChannel);
}

void LedStripAdapterBase::setRangeLedColors(uint16_t fromLedIndex, uint16_t toLedIndex, uint8_t redChannel,
                                               uint8_t greenChannel, uint8_t blueChannel, uint8_t alphaChannel) {
    // Loop through the LED range to set the values
    for(uint16_t i = fromLedIndex; i < toLedIndex; i++)
        this->setLedColor(i, redChannel, greenChannel, blueChannel, alphaChannel);
}

void LedStripAdapterBase::setRangeLedColorsCombinedChannels(uint16_t fromLedIndex, uint16_t toLedIndex, uint32_t combinedColorValue) {
    // Loop through the LED range to set the values
    for(uint16_t i = fromLedIndex; i < toLedIndex; i++)
        this->setLedColorCombinedChannels(i, combinedColorValue);
}

void LedStripAdapterBase::setAllLedColors(LedStripColor color) {
    // Set all the LEDs using the range methods
    this->setRangeLedColors(0, this->getLedCount(), color);
}

void LedStripAdapterBase::setAllLedColors(uint8_t redChannel) {
    // Set all the LEDs using the range methods
    this->setRangeLedColors(0, this->getLedCount(), redChannel);
}

void LedStripAdapterBase::setAllLedColors(uint8_t redChannel, uint8_t greenChannel) {
    // Set all the LEDs using the range methods
    this->setRangeLedColors(0, this->getLedCount(), redChannel, greenChannel);
}

void LedStripAdapterBase::setAllLedColors(uint8_t redChannel, uint8_t greenChannel, uint8_t blueChannel) {
    // Set all the LEDs using the range methods
    this->setRangeLedColors(0, this->getLedCount(), redChannel, greenChannel, blueChannel);
}

void LedStripAdapterBase::setAllLedColors(uint8_t redChannel, uint8_t greenChannel, uint8_t blueChannel,
                                             uint8_t alphaChannel) {
    // Set all the LEDs using the range methods
    this->setRangeLedColors(0, this->getLedCount(), redChannel, greenChannel, blueChannel, alphaChannel);
}

void LedStripAdapterBase::setAllLedColorsCombinedChannels(uint32_t combinedColorValue) {
    // Set all the LEDs using the range methods
    this->setRangeLedColorsCombinedChannels(0, this->getLedCount(), combinedColorValue);
}

bool LedStripAdapterBase::hasRedChannelSupport() {
    return this->getColorChannelCount() >= 1;
}

bool LedStripAdapterBase::hasGreenChannelSupport() {
    return this->getColorChannelCount() >= 2;
}

bool LedStripAdapterBase::hasBlueChannelSupport() {
    return this->getColorChannelCount() >= 3;
}

bool LedStripAdapterBase::hasAlphaChannelSupport() {
    return this->getColorChannelCount() >= 4;
}