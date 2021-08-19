#ifndef OSW_SERVICE_TASKEXAMPLE_H
#define OSW_SERVICE_TASKEXAMPLE_H

#include "osw_service.h"

class OswServiceTaskExample : public OswServiceTask {
 public:
  OswServiceTaskExample() : OswServiceTask("example", 64, 10000) {};
  void setup(OswHal* hal);
  void loop();
  void stop();
  ~OswServiceTaskExample(){};
};

#endif