#include "./services/OswServiceTaskMemMonitor.h"

#include "osw_hal.h"
#include "services/OswServiceManager.h"

void OswServiceTaskMemMonitor::setup(OswHal* hal) { OswServiceTask::start<OswServiceTaskMemMonitor>(hal); }

/**
 * Prints the current memory information
 */
void OswServiceTaskMemMonitor::loop() {
  this->printStats();
}

/**
 * This should periodically be called from the loop on core 1, it updates his stack high
 * watermarks and also calls printStats() on changes
 */
void OswServiceTaskMemMonitor::updateLoopTaskStats() {
  unsigned core1 = uxTaskGetStackHighWaterMark(nullptr);
  if (core1 != this->core1high) {
    this->core1high = core1;
    this->printStats();
  }
}

/**
 * Send a overview regarding the current stack watermarks (core 0&1), heap watermarks and heap useage to serial
 */
void OswServiceTaskMemMonitor::printStats() {
  Serial.println("========= Memory Monitor =========");
  const unsigned maxCore1 =
      8192;  // This value is based on https://github.com/espressif/arduino-esp32/blob/master/cores/esp32/main.cpp
  Serial.print("core 1 (high):\t");
  Serial.print(maxCore1 - this->core1high);
  Serial.print("B of ");
  Serial.print(maxCore1);
  Serial.println("B");

  Serial.print("heap (high):\t");
#if defined(GPS_EDITION) || defined(GPS_EDITION_ROTATED)
  Serial.print((ESP.getHeapSize() + ESP.getPsramSize()) - this->heapHigh);
#else
  Serial.print(ESP.getHeapSize() - this->heapHigh);
#endif
  Serial.print("B of ");
  Serial.print(ESP.getHeapSize());
  Serial.println("B");

  Serial.print("heap (curr):\t");
  Serial.print(ESP.getHeapSize() - ESP.getFreeHeap());
  Serial.print("B of ");
  Serial.print(ESP.getHeapSize());
  Serial.println("B");

#if defined(GPS_EDITION) || defined(GPS_EDITION_ROTATED)
  Serial.print("psram (curr):\t");
  Serial.print(ESP.getPsramSize() - ESP.getFreePsram());
  Serial.print("B of ");
  Serial.print(ESP.getPsramSize());
  Serial.println("B");
#endif

  // TODO Maybe fetch current largest available heap size and calc "fragmentation" percentage.
}
