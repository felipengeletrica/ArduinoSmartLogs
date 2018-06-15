#include <Arduino.h>
#include "../lib/Log/logs.h"

void setup() {

  Serial.begin(115200);
  Serial.println();
  Serial.println();

  //Initalized logs level
  log_setserial(&Serial);
  log_setlevel(LOG_TRACE);
  log_setquiet(false);

  Serial.println("Welcome logs for ESP8266 and outhers!");
  Serial.println("Platformm Arduino!");
  Serial.println("ENJOY :)");

}

void loop() {

    static int cont = 0;
    cont++;

    logtrace("Trace level log");
    logtrace("Cont: %d", cont);
    delay(1000);
    logdebug("Debug log");
    delay(1000);
    logwarn("Log Warm");
}
