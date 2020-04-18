
#include <DS3231.h>
#include <SD.h>
#include <SPI.h>

// Init the DS3231 using the hardware interface
DS3231  rtc(SDA, SCL);

const int MICROPHONE_DO_PIN = 7;
const int MEASURE_LED_PIN = 2;
const int WAITING_LED_PIN = 3;
const int SD_PIN_CS = 10;

File DATAFILE;

void setup()
{
  Serial.begin(9600);
  rtc.begin();
  pinMode(MICROPHONE_DO_PIN, INPUT);

  // SD CS PIN
  pinMode(SD_PIN_CS, OUTPUT);

  // Initialize SD card
  if (SD.begin()) {
    Serial.println("SD Card ready to use!");
  } else {
    Serial.println("ERROR: SD Card couldn't be initialized!"); 
    return;
  }

  // create or open File
  Serial.println("Opening datafile...");
  DATAFILE = SD.open("TESTFILE.txt", FILE_WRITE);

  // check if file got opened
  if (DATAFILE) {
    // write to datafile
    Serial.println("Writing line of data to datafile...");
    DATAFILE.println("Test123");
    DATAFILE.close();
    Serial.println("Writing line of data was successful!");
  } else {
    // error message when dile got error while opening
    Serial.println("ERROR: Opening Datafile returned an error!");
  }
   
  // set up status LEDs
  pinMode(WAITING_LED_PIN, OUTPUT);
  pinMode(MEASURE_LED_PIN, OUTPUT);

  // blink lights 2 times
  digitalWrite(WAITING_LED_PIN, HIGH);
  digitalWrite(MEASURE_LED_PIN, HIGH);
  delay(500);
  digitalWrite(WAITING_LED_PIN, LOW);
  digitalWrite(MEASURE_LED_PIN, LOW);
  delay(500);
  digitalWrite(WAITING_LED_PIN, HIGH);
  digitalWrite(MEASURE_LED_PIN, HIGH);
  delay(500);
  digitalWrite(WAITING_LED_PIN, LOW);
  digitalWrite(MEASURE_LED_PIN, LOW);
  delay(500);

  // only waiting on
  digitalWrite(WAITING_LED_PIN, HIGH);
}

void loop() 
{
  // Log Mic hit
  int active = digitalRead(MICROPHONE_DO_PIN);
  if (active) {
    // turn LED on
    digitalWrite(MEASURE_LED_PIN, HIGH);
    
    // send HIT
    Serial.print("HIT!!! ");
    
    // Send Day-of-Week
    Serial.print(rtc.getDOWStr());
    Serial.print(" ");
    
    // Send date
    Serial.print(rtc.getDateStr());
    Serial.print(" -- ");
  
    // Send time
    Serial.println(rtc.getTimeStr());
    
    // turn LED off
    digitalWrite(MEASURE_LED_PIN, LOW);
  }
}
