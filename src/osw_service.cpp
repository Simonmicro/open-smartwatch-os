#include "osw_service.h"

void OswServiceTask::loop() {
#ifdef DEBUG
  Serial.println(String(__FILE__) + ": Service " + this->m_taskName + " is sleeping...");
#endif
  delay(this->m_taskSleepTime);
}

void OswServiceTask::stop() {
  vTaskDelete(&this->m_taskHandle);
  this->m_taskHandle = nullptr;
}