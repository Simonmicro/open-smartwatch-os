#include "./services/OswServiceTaskGPS.h"

#include "osw_hal.h"

void OswServiceTaskGPS::setup(OswHal* hal) {
  OswServiceTask::start<OswServiceTaskGPS>(hal);
#if defined(GPS_EDITION) || defined(GPS_EDITION_ROTATED)

  hal->setupGps();

  Serial.print("PSRAM free: ");
  Serial.println(ESP.getMinFreePsram());
  Serial.print("Free Memory: ");
  Serial.println((int)xPortGetFreeHeapSize());
#endif
}

void OswServiceTaskGPS::loop() {
#if defined(GPS_EDITION) || defined(GPS_EDITION_ROTATED)
  this->m_hal->gpsParse();
#endif
}
