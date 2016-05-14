# Universal LED strip driver for Arduino
An universal LED strip driver for Arduino.
This LED strip drivers supports various features like animations and strip state buffering.

Please check the `ArduinoUniversalLedStripDriver.ino` file as usage example.

### Supported LED strips
The following LED strip types are currently supported:

- **LPD8806** based LED strips

You can easily add support for different LED strip types.
To do this, create a new adapter and LED strip instance for your specific type.
Check out the already existing adapters and LED strip instances for more information.

### Usage
This driver allows you to use LED strips very easily. However, in order to use it, some steps are required.

At first, before you can use the driver you need to include the required header files. Simply use 
`#include "LedStripDriver.h"` in your project.

There are various adapters available to support various types of LED strips.
The correct adapter and LED strip instance needs to be used to make it work properly.
If you'd be using a `LPD8806`-type LED strip, you should use `LedStripLPD8806`.
For ease of use, we can create an alias using:
`typedef LedStripLPD8806 LedStrip;`.

Now, you need to create a LED strip instance. There are various ways to achieve this, this is one of them:
`LedStrip strip = LedStrip(LED_COUNT, DATA_PIN, CLOCK_PIN);`

You need to instantiate every LED strip instance before using it, simply call the `strip.init();` method for this.

The LED strip is initialized. It's now ready to be used. Remember that methods like `strip.setAllLedColors()` change the LED state on your Arduino.
The `strip.render()` methods needs to be called to render the LED strip state to the physical device.


### Minimal example
    #include "LedStripDriver.h"
    
    // Create an alias for ease of use
    typedef LedStripAdapterLPD8806 LedStrip;
    
    /**
     * Called on Arduino setup.
     */
    void setup() {
        // Define the LED strip
        // (62 LEDs, data pin = 2, clock pin = 3)
        LedStrip strip = LedStrip(62, 2, 3);
    
        // Initialize the LED strip before using it
        strip.init();
    
        // Make the second LED red
        strip.setLedColor(1, LedStripColor(255, 0, 0));
    
        // Render the LED strip
        strip.render();
    }

Please check the `ArduinoUniversalLedStripDriver.ino` file as usage example.