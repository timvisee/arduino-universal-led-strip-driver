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

#include "LedStripBase.h"

LedStripBase::LedStripBase(uint16_t ledCount) {
    this->ledCount = ledCount;
}

LedStripBase::LedStripBase(uint16_t ledCount, LedStripAdapterBase* adapter) {
    this->ledCount = ledCount;
    this->adapter = adapter;
}

LedStripBase::~LedStripBase() {
    // Explicitly delete dynamically allocated LED strip adapter
    delete &this->adapter;
}

uint16_t LedStripBase::getLedCount() {
    return this->ledCount;
}

void LedStripBase::setLedCount(uint16_t ledCount) {
    // Set the LED count field
    this->ledCount = ledCount;

    // Set the adapter's LED count
    return this->adapter->setLedCount(ledCount);
}

LedStripAdapterBase* LedStripBase::getAdapter() {
    return this->adapter;
}

void LedStripBase::setAdapter(LedStripAdapterBase* adapter) {
    this->adapter = adapter;
}

void LedStripBase::clear() {
    this->clear(true);
}

void LedStripBase::clear(bool render) {
    // Clear the LEDs
    this->setAllLedColors(LedStripColor::black());

    // Render
    if(render)
        this->render();
}

LedStripColor LedStripBase::getLedColor(uint16_t ledIndex) {
    return this->adapter->getLedColor(ledIndex);
}

void LedStripBase::setLedColor(uint16_t ledIndex, LedStripColor color) {
    this->adapter->setLedColor(ledIndex, color);
}

void LedStripBase::setLedColor(uint16_t ledIndex, uint8_t redChannel) {
    this->adapter->setLedColor(ledIndex, redChannel);
}

void LedStripBase::setLedColor(uint16_t ledIndex, uint8_t redChannel, uint8_t greenChannel) {
    this->adapter->setLedColor(ledIndex, redChannel, greenChannel);
}

void LedStripBase::setLedColor(uint16_t ledIndex, uint8_t redChannel, uint8_t greenChannel, uint8_t blueChannel) {
    this->adapter->setLedColor(ledIndex, redChannel, greenChannel, blueChannel);
}

void LedStripBase::setLedColor(uint16_t ledIndex, uint8_t redChannel, uint8_t greenChannel, uint8_t blueChannel,
                               uint8_t alphaChannel) {
    this->adapter->setLedColor(ledIndex, redChannel, greenChannel, blueChannel, alphaChannel);
}

void LedStripBase::setRangeLedColors(uint16_t fromLedIndex, uint16_t toLedIndex, LedStripColor color) {
    this->adapter->setRangeLedColors(fromLedIndex, toLedIndex, color);
}

void LedStripBase::setRangeLedColors(uint16_t fromLedIndex, uint16_t toLedIndex, uint8_t redChannel) {
    this->adapter->setRangeLedColors(fromLedIndex, toLedIndex, redChannel);
}

void LedStripBase::setRangeLedColors(uint16_t fromLedIndex, uint16_t toLedIndex, uint8_t redChannel,
                                     uint8_t greenChannel) {
    this->adapter->setRangeLedColors(fromLedIndex, toLedIndex, redChannel, greenChannel);
}

void LedStripBase::setRangeLedColors(uint16_t fromLedIndex, uint16_t toLedIndex, uint8_t redChannel, uint8_t greenChannel,
                                     uint8_t blueChannel) {
    this->adapter->setRangeLedColors(fromLedIndex, toLedIndex, redChannel, greenChannel, blueChannel);
}

void LedStripBase::setRangeLedColors(uint16_t fromLedIndex, uint16_t toLedIndex, uint8_t redChannel, uint8_t greenChannel,
                                     uint8_t blueChannel, uint8_t alphaChannel) {
    this->adapter->setRangeLedColors(fromLedIndex, toLedIndex, redChannel, greenChannel, blueChannel, alphaChannel);
}

void LedStripBase::setAllLedColors(LedStripColor color) {
    this->adapter->setAllLedColors(color);
}

void LedStripBase::setAllLedColors(uint8_t redChannel) {
    this->adapter->setAllLedColors(redChannel);
}

void LedStripBase::setAllLedColors(uint8_t redChannel, uint8_t greenChannel) {
    this->adapter->setAllLedColors(redChannel, greenChannel);
}

void LedStripBase::setAllLedColors(uint8_t redChannel, uint8_t greenChannel, uint8_t blueChannel) {
    this->adapter->setAllLedColors(redChannel, greenChannel, blueChannel);
}

void LedStripBase::setAllLedColors(uint8_t redChannel, uint8_t greenChannel, uint8_t blueChannel,
                                     uint8_t alphaChannel) {
    this->adapter->setAllLedColors(redChannel, greenChannel, blueChannel, alphaChannel);
}