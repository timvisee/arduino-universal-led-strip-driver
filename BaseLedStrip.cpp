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

#include "BaseLedStrip.h"

BaseLedStrip::BaseLedStrip(uint8_t ledCount) {
    this->ledCount = ledCount;
}

BaseLedStrip::BaseLedStrip(uint8_t ledCount, BaseLedStripAdapter adapter) {
    this->ledCount = ledCount;
    this->adapter = adapter;
}

BaseLedStrip::~BaseLedStrip() {
    // Explicitly delete all fields
//    delete &this->ledCount;
//    delete &this->adapter;
}

uint8_t BaseLedStrip::getLedCount() {
    return this->ledCount;
}

BaseLedStripAdapter BaseLedStrip::getAdapter() {
    return this->adapter;
}

void BaseLedStrip::setAdapter(BaseLedStripAdapter adapter) {
    this->adapter = adapter;
}

LedStripColor BaseLedStrip::getLedColor(uint8_t ledIndex) {
    return this->adapter.getLedColor(ledIndex);
}

void BaseLedStrip::setLedColor(uint8_t ledIndex, LedStripColor color) {
    return this->adapter.setLedColor(ledIndex, color);
}

void BaseLedStrip::setLedColor(uint8_t ledIndex, uint8_t redChannel) {
    this->adapter.setLedColor(ledIndex, redChannel);
}

void BaseLedStrip::setLedColor(uint8_t ledIndex, uint8_t redChannel, uint8_t greenChannel) {
    this->adapter.setLedColor(ledIndex, redChannel, greenChannel);
}

void BaseLedStrip::setLedColor(uint8_t ledIndex, uint8_t redChannel, uint8_t greenChannel, uint8_t blueChannel) {
    this->adapter.setLedColor(ledIndex, redChannel, greenChannel, blueChannel);
}

void BaseLedStrip::setLedColor(uint8_t ledIndex, uint8_t redChannel, uint8_t greenChannel, uint8_t blueChannel,
                               uint8_t alphaChannel) {
    this->adapter.setLedColor(ledIndex, redChannel, greenChannel, blueChannel, alphaChannel);
}