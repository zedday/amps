/**
 * @ Name: AMPS (ATX Made Power Supply)
 * @ Author: Zedday
 * @ Mail: zedday@zlab.fr
 * @ Create Time: 2019-10-24 23:05:31
 * @ Description: Control the screen and display the measures from the current sensors
 */
#include <Wire.h>
#include <hd44780.h>                       // Main hd44780 header
#include <hd44780ioClass/hd44780_I2Cexp.h> // I2C expander i/o class header

#define VERSION "0.1"

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

// Initialize LiquidCrystal library (auto detect i2c address)
hd44780_I2Cexp lcd;


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
    lcd.setCursor(0, 0);
    lcd.print(aLine1);
    // Print second line
    lcd.setCursor(0,1);
    lcd.print(aLine2);

}

/**
 * Print the requested screen
 * @param aScreenIndex : Index of the screen to display
 **/
void printScreen(uint8_t aScreenIndex)
{
    lcd.clear();
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
    // Print boot message
    delay(1000);
    lcd.setCursor(3,0);
    lcd.print("A  M  P  S");
    delay(1000);
    lcd.setCursor(5,1);
    lcd.print("<ZLab>");
    delay(2500); // Wait 2,5s
}

/**
 * Arduino setup function
 **/
void setup()
{
    // Set up the LCD's number of columns and rows
    lcd.begin(16,2);
    lcd.clear();
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
    // Test : Display all the screen
    for(int i=0;i<4;i++)
    {
        printScreen(i);
        delay(4000); // Wait 4s
    }
    // uint8_t vScreenIndex = SCREEN_5V; // Default screen is 5V

    // Print the selected screen
    // printScreen(vScreenIndex);

    // Read button state and modify the screen variable
    // readButtons(&vScreenIndex);
}
