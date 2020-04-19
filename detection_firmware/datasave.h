/*
 * All the data saving mechanics
 */

// import librarys
#include <SD.h>
#include <SPI.h>

File DATAFILE;

void sd_file_init() {
  logSerialLineln("Initializing SD Card...");
  
  // set pin mode as output
  pinMode(SD_PIN_CS, OUTPUT);
  
  // Initialize SD card
  if (SD.begin()) {
    logSerialLineln("SD Card ready to use!");
  } else {
    logSerialLineln("ERROR: SD Card couldn't be initialized!"); 
    return;
  }

  // Check if file exists, if not initialize with headers
  if (SD.exists(SD_DATAFILE_NAME)) {
    logSerialLineln("File " + SD_DATAFILE_NAME + " was found on the SD Card!");
  } else {
    logSerialLineln("Didn't find " + SD_DATAFILE_NAME + ", initializing file...");
    
    logSerialLineln("Opening datafile...");
    DATAFILE = SD.open(SD_DATAFILE_NAME, FILE_WRITE);

    // check if file got opened
    if (DATAFILE) {
      // write to datafile
      logSerialLineln("Writing line of data to datafile...");
      DATAFILE.println("timestamp,frequency,countedHits");
      DATAFILE.close();
      logSerialLineln("Writing line of data was successful!");
    } else {
      // error message when dile got error while opening
      logSerialLineln("ERROR: Opening Datafile returned an error!");
    }
  }
}

void sd_write_to_datafile(String dataline) {
  // create or open File
  logSerialLineln("Opening datafile...");
  DATAFILE = SD.open(SD_DATAFILE_NAME, FILE_WRITE);

  // check if file got opened
  if (DATAFILE) {
    // write to datafile
    logSerialLineln("Writing line of data to datafile...");
    DATAFILE.println(dataline);
    DATAFILE.close();
    logSerialLineln("Writing line of data was successful!");
  } else {
    // error message when dile got error while opening
    logSerialLineln("ERROR: Opening Datafile returned an error!");
  }
}

void log_data(float count, int hitCounter) {
  DATASTRING = String(rtc_get_current_time()) + "," + String(count) + "," + String(hitCounter);
  sd_write_to_datafile(DATASTRING);
}
