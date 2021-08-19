#include "./services/OswServiceManager.h"

#include "./services/OswServiceTasks.h"
#include "esp_task_wdt.h"

/**
 * This enables all currently known services using their setup() and starts the loop() on core 0
 */
void OswServiceManager::setup(OswHal *hal) {
  for (unsigned char i = 0; i < oswServiceTasksCount; i++) oswServiceTasks[i]->setup(hal);
  this->active = true;
}

void OswServiceManager::stop() {
  for (unsigned char i = 0; i < oswServiceTasksCount; i++) oswServiceTasks[i]->stop();
  this->active = false;
}