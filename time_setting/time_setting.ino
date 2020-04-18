#include <DS3231.h>

DS3231 rtc(SDA, SCL);

void setup() {
  Serial.begin(9600);

  rtc.begin();

  // The following lines can be uncommented to set the date and time
  rtc.setDOW(WEDNESDAY);      // Day 
  rtc.setTime(17, 55, 0);     // HOUR, MIN, SEC (24 HOUR FORMAT)
  rtc.setDate(15, 4, 2020);   // DATE, MONTH, JEAR
}

void loop() {
  Serial.println(String(rtc.getUnixTime(rtc.getTime())));
  
  // Send date
  Serial.print(rtc.getDateStr());
  Serial.print(" ");

  // Send time
  Serial.println(rtc.getTimeStr());
  
  // Wait one second before repeating 
  delay (1000);
}
