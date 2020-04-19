/*
 * Module to control the time functions
 * 
 * library used:
 * http://www.rinkydinkelectronics.com/library.php?id=73
 */

// include all librarys
#include <DS3231.h>

// initialize the hardware interface
DS3231 rtc(SDA, SCL);

void rtc_init() {
  // Initialize the rtc object
  logSerialLineln("Initializing the RTC...");
  rtc.begin();
  logSerialLineln("Current time: " + String(rtc.getDateStr()) + " " + String(rtc.getTimeStr()));
}

long rtc_get_current_time() {
  // return unix time stamp
  return rtc.getUnixTime(rtc.getTime());
}
