#ifndef OSW_SERVICE_TASKMEMMONITOR_H
#define OSW_SERVICE_TASKMEMMONITOR_H

#include "osw_service.h"

class OswServiceTaskMemMonitor : public OswServiceTask {
 public:
  OswServiceTaskMemMonitor() : OswServiceTask("mmonitor", 1024, 10000) {};
  void setup(OswHal* hal);
  void loop();
  void updateLoopTaskStats();  // Call this from the main loop regulary!
  void printStats();
  ~OswServiceTaskMemMonitor(){};

 private:
  unsigned core1high;
  unsigned heapHigh;
};

#endif