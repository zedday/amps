/**
 * @ Name: AMPS (ATX Made Power Supply)
 * @ Author: Zedday
 * @ Mail: zedday@zlab.fr
 * @ Create Time: 2019-10-24 23:05:31
 * @ Description: Control the screen and display the measures from the current sensors
 */
#include <Arduino.h>

// Pins constants
const uint8_t BUTTON_PREVIOUS = 6;
const uint8_t BUTTON_NEXT = 7;

// Index of the differents screens
const uint8_t SCREEN_5V_USB = 0;
const uint8_t SCREEN_3_3V = 1;
const uint8_t SCREEN_5V = 2;
const uint8_t SCREEN_12V = 3;

/**
 * Boot sequence.
 * Print boot message, then print the default screen
 **/
void boot()
{
    // TODO: Print boot message

    // Wait 2 seconds
    delay(2000);
}

/**
 * Read button state and increments the screen index in consequence
 * @param _aScreen : Pointer to the screen index
 **/
void read_buttons(uint8_t *_aScreenIndex)
{
    // Read buttons state
    bool vNextButton = false;     // TODO:
    bool vPreviousButton = false; // TODO:

    // Do nothing if both button are pressed
    if (vNextButton != vPreviousButton)
    {
        // TODO: Manage button presses
    }
}

/**
 * Print the requested screen
 * @param aScreenIndex : Index of the screen to display
 **/
void print_screen(uint8_t aScreenIndex)
{
    switch (aScreenIndex)
    {
    case (uint8_t) SCREEN_5V_USB:
        // TODO: Print 5V screen
        break;
    case (uint8_t) SCREEN_3_3V:
        // TODO: Print 3.3V screen
        break;
    case (uint8_t) SCREEN_5V:
        // TODO: Print 5V screen
        break;
    case (uint8_t) SCREEN_12V:
        // TODO: Print 12V screen
        break;
    default:
        // TODO Print default screen
        break;
    }
}

/**
 * Arduino setup function
 **/
void setup()
{
    // TODO: Configure pins for LCD screen

    // TODO: Configure pins for current sensors

    // TODO: Configure pins for the button

    // Launch boot sequence
    boot();
}

/**
 * Arduino main loop
 **/
void loop()
{
    uint8_t vScreenIndex = SCREEN_5V; // Default screen is 5V

    // Print the selected screen

    // Read button state and modify the screen variable
    read_buttons(&vScreenIndex);
}