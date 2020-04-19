/*
 * Author: Anton Heitz, 2020
 * 
 * A Piece of software to read and save information regarding noise-signals
 * 
 */

// include all modules
#include "constants.h"
#include "variables.h"
#include "serialcom.h"
#include "timecontrol.h"
#include "datasave.h"
#include "measureOperations.h"

void setup() {
  // set up status LEDs
  pinMode(WAITING_LED_PIN, OUTPUT);
  pinMode(MEASURE_LED_PIN, OUTPUT);

  // turn both leds on
  waitingLedOn();
  measuringLedOn();

  // initial calculations
  DELAY_BETWEEN_MEASURES_MILLIS = (long) SECONDS_BETWEEN_MEASUREMENTS * 1000;
  
  // begin serial
  serial_init();

  // init rtc module
  rtc_init();

  // init sound module
  microphone_init();
  
  // init SD card
  sd_file_init();

  // turn measure off
  measuringLedOff();

  // wait 5 sec
  delay(5000);
}

void loop() {
  // sign measure at status leds
  measuringLedOn();
  waitingLedOff();
  
  // measure and log frequency
  measure_frequency();

  // sign waiting at status leds
  waitingLedOn();
  measuringLedOff();

  // wait for defined amount of seconds
  logSerialLineln("Waiting for " + String(SECONDS_BETWEEN_MEASUREMENTS) + " Seconds...");
  delay(DELAY_BETWEEN_MEASURES_MILLIS);
}

void waitingLedOn() {
  digitalWrite(WAITING_LED_PIN, HIGH);
}

void waitingLedOff() {
  digitalWrite(WAITING_LED_PIN, LOW);
}

void measuringLedOn() {
  digitalWrite(MEASURE_LED_PIN, HIGH);
}

void measuringLedOff() {
  digitalWrite(MEASURE_LED_PIN, LOW);
}
