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

void BaseLedStripAdapter::setLedColor(uint8_t ledIndex, LedStripColor color) { }

void BaseLedStripAdapter::setLedColor(uint8_t ledIndex, uint8_t redChannel) { }

void BaseLedStripAdapter::setLedColor(uint8_t ledIndex, uint8_t redChannel, uint8_t greenChannel) { }

void BaseLedStripAdapter::setLedColor(uint8_t ledIndex, uint8_t redChannel, uint8_t greenChannel,
                                      uint8_t blueChannel) { }

void BaseLedStripAdapter::setLedColor(uint8_t ledIndex, uint8_t redChannel, uint8_t greenChannel, uint8_t blueChannel,
                                      uint8_t alphaChannel) { }

uint32_t BaseLedStripAdapter::getLedColorCombinedChannels(uint8_t ledIndex) {
    return 0;
}

void BaseLedStripAdapter::setLedColorCombinedChannels(uint8_t ledIndex, uint32_t combinedColorValue) { }

uint8_t BaseLedStripAdapter::getColorChannelCount() {
    return 0;
}

uint8_t BaseLedStripAdapter::getColorValueMax() {
    return 0;
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

LedStripColor BaseLedStripAdapter::getLedColor(uint8_t ledIndex) {
    return LedStripColor();
}