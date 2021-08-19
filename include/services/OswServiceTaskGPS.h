#ifndef OSW_SERVICE_TASKGPS_H
#define OSW_SERVICE_TASKGPS_H

#include "osw_service.h"

class OswServiceTaskGPS : public OswServiceTask {
 public:
  OswServiceTaskGPS() : OswServiceTask("gps", 1024, 1000) {};
  void setup(OswHal* hal);
  void loop();
  ~OswServiceTaskGPS(){};
};

#endif