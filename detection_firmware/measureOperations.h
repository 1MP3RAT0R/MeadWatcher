/*
 * Module for the sound counting operation
 */

void microphone_init() {
  pinMode(MICROPHONE_DO_PIN, INPUT);

  // calculate delay of counter
  COUNTER_DELAY_MILLIS = 1000 / MAX_HZ;
}

float measure_frequency() {
  logSerialLine("Starting measurement for ");
  logSerialLine(String(SECONDS_FOR_MEASUREMENT));
  logSerialLineln(" Seconds...");

  // reset impulse counter
  IMPULSE_COUNTER = 0;

  // get exit system millis (not rtc, not needed here)
  EXIT_MILLIS = millis() + (SECONDS_FOR_MEASUREMENT * 1000);

  // run loop for the amount of seconds defined
  while (EXIT_MILLIS >= millis()) {
    int activ = digitalRead(MICROPHONE_DO_PIN);
    if (activ) {
      IMPULSE_COUNTER = IMPULSE_COUNTER + 1;
      logSerialLine("HIT: ");
      logSerialLineln(String(IMPULSE_COUNTER));

      // wait depending on max hertz to prevent multiple-counting of one impulse
      delay(COUNTER_DELAY_MILLIS);
    }
  }

  // calculate Frequency (per second)
  BUBBLE_FREQUENCY = (float) IMPULSE_COUNTER / (float) SECONDS_FOR_MEASUREMENT;
  
  logSerialLine("Measured frequency: ");
  logSerialLine(String(BUBBLE_FREQUENCY));
  logSerialLineln(" HZ");

  // return Frequency
  log_data(BUBBLE_FREQUENCY, IMPULSE_COUNTER);
}
