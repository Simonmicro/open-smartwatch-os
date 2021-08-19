#ifndef OSW_SERVICE_MANAGER_H
#define OSW_SERVICE_MANAGER_H
#include "osw_hal.h"
#include "osw_service.h"

class OswServiceManager {
 public:
  static OswServiceManager &getInstance() {
    static OswServiceManager instance;
    return instance;
  }

  void setup(OswHal *hal);
  void stop();

 private:
  OswServiceManager(){};
  bool active = false;

  OswServiceManager(OswServiceManager const &);
  void operator=(OswServiceManager const &);
};
#endif
