#include "./services/OswServiceTaskExample.h"
#include "osw_hal.h"
#include <time.h>

void OswServiceTaskExample::setup(OswHal* hal) {
    OswServiceTask::start<OswServiceTaskExample>(hal);
    Serial.println(String(__FILE__)  + "->" + __FUNCTION__ + "()");
}

void OswServiceTaskExample::loop() {
    OswServiceTask::loop();
    Serial.println(String(__FILE__)  + "->" + __FUNCTION__ + "()");
}

void OswServiceTaskExample::stop() {
    OswServiceTask::stop();
    Serial.println(String(__FILE__)  + "->" + __FUNCTION__ + "()");
}