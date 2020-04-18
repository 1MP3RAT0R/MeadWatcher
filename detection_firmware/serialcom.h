/*
 * The library for serial communication
 */

void serial_init() {
  if (DEBUG_MODE) {
    Serial.begin(SERIAL_BAUD_RATE);
  }
}

void logSerialLine(String data) {
  if (DEBUG_MODE) {
    Serial.print(data);
  }
}

void logSerialLineln(String data) {
  if (DEBUG_MODE) {
    Serial.println(data);
  }
}
