/*
 * Constatnts to be initialized at the begin
 */

// debug mode enables Serial Connection, not to be used with powerbank
const boolean DEBUG_MODE = false;

// General
const int SERIAL_BAUD_RATE = 9600;
const String SD_DATAFILE_NAME = "data.txt";
const int SECONDS_BETWEEN_MEASUREMENTS = 60;
const int SECONDS_FOR_MEASUREMENT = 30;
const int MAX_HZ = 10;

// PINS Arduino Uno

/*
 * Sign lED pins
 * 
 * Measuring - 2
 * Waiting - 3
 */

const int MEASURE_LED_PIN = 3;
const int WAITING_LED_PIN = 2;

/*
 * Microphone Pins
 * 
 * Digital out (DO) - Pin 7
 */
const int MICROPHONE_DO_PIN = 7;

/*
 * SD CARD PINS
 * 
 * MOSI - Digital 11
 * MISO - Digital 12
 * SCK - Digital 13
 * CS - Digital 10
 */
const int SD_PIN_CS = 10;

/*
 * DS3231 Pins
 * 
 * SDA pin - Analog 4
 * SCL pin - Analog 5
 */
