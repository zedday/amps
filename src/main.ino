/**
 * @ Name: AMPS (ATX Made Power Supply)
 * @ Author: Zedday
 * @ Mail: zedday@zlab.fr
 * @ Create Time: 2019-10-24 23:05:31
 * @ Description: Control the screen and display the measures from the current sensors
 */
#include <LiquidCrystal.h>

// Pins constants
const uint8_t BUTTON_PREVIOUS = 6;
const uint8_t BUTTON_NEXT = 7;

// Index of the differents screens
const uint8_t SCREEN_5V_USB = 0;
const uint8_t SCREEN_3_3V = 1;
const uint8_t SCREEN_5V = 2;
const uint8_t SCREEN_12V = 3;

// Screen header strings
const String HEADER_5V_USB = "1 - 5V USB";
const String HEADER_3_3V = "2 - 3.3V Line";
const String HEADER_5V = "3 - 5V Line";
const String HEADER_12V = "4 - 12V Line";

// Initialize LiquidCrystal library
LiquidCrystal vLCD(1, 2, 3, 4, 5, 6); // FIXME: Modify with the correct the pins

/**
 * Read button state and increments the screen index in consequence
 * @param _aScreen : Pointer to the screen index
 **/
void readButtons(uint8_t *_aScreenIndex)
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
 * Print message on the LCD screen
 * @param _aLine1 : Text to display on the first line
 * @param _aLine2 : Text to display on the second line
 **/
void printLCD(String aLine1, String aLine2)
{
    // Print first line
    vLCD.setCursor(0, 0);
    vLCD.print(aLine1);
    // Print second line
    vLCD.setCursor(1,0);
    vLCD.print(aLine2);

}

/**
 * Print the requested screen
 * @param aScreenIndex : Index of the screen to display
 **/
void printScreen(uint8_t aScreenIndex)
{
    switch (aScreenIndex)
    {
    case (uint8_t)SCREEN_5V_USB:
        // TODO: Get the 5V USB current sensor info
        printLCD(HEADER_5V_USB, "XX.XXXA  XXX.XXW");
        break;
    case (uint8_t)SCREEN_3_3V:
        // TODO: Get the 3.3V current sensor info
        printLCD(HEADER_3_3V, "XX.XXXA  XXX.XXW");
        break;
    default:
    case (uint8_t)SCREEN_5V:
        // TODO: Get the 5V current sensor info
        printLCD(HEADER_5V, "XX.XXXA  XXX.XXW");
        break;
    case (uint8_t)SCREEN_12V:
        // TODO: Get the 12V USB current sensor info
        printLCD(HEADER_12V, "XX.XXXA  XXX.XXW");
        break;
    }
}

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
    printScreen(vScreenIndex);

    // Read button state and modify the screen variable
    readButtons(&vScreenIndex);
}