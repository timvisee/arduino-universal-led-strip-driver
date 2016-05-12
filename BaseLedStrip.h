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

#ifndef LEDSTRIPCONTROLLER_LEDSTRIPBASE_H
#define LEDSTRIPCONTROLLER_LEDSTRIPBASE_H

#include "LPD8806.h"
#include "SPI.h"

#include "BaseLedStripAdapter.h"

/**
 * LedStrip base class.
 * This class represents the base of a physical LED strip, and provides an interface to control the strip.
 *
 * @author Tim Visee
 * @website http://timvisee.com/
 * @version 1.1
 */
class BaseLedStrip {
private:
    /**
     * Number of LEDs this LED strip contains.
     */
    uint8_t ledCount;

    /**
     * LED strip adapter for the used LED strip type.
     */
    BaseLedStripAdapter adapter;

protected:
    /**
     * Constructor.
     * The LED strip adapter must be specified manually before this LED strip instance is used.
     *
     * @param ledCount Number of LEDs.
     */
    BaseLedStrip(uint8_t ledCount);

    /**
     * Constructor.
     *
     * @param ledCount Number of LEDs.
     * @param adapter LED strip adapter for the used LED strip type.
     */
    BaseLedStrip(uint8_t ledCount, BaseLedStripAdapter adapter);

public:
    /**
     * Get the number of LEDs this LED strip has.
     *
     * @return LED count.
     */
    uint8_t getLedCount();

    /**
     * Get the LED strip adapter instance.
     *
     * @return LED strip adapter.
     */
    BaseLedStripAdapter getAdapter();

protected:
    /**
     * Set the LED strip adapter instance.
     *
     * @param adapter LED strip adapter.
     */
    void setAdapter(BaseLedStripAdapter adapter);
};

#endif // LEDSTRIPCONTROLLER_LEDSTRIPBASE_H
