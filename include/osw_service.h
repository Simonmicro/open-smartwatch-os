#ifndef OSW_SERVICE_H
#define OSW_SERVICE_H
#include <osw_app.h>

class OswServiceTask {
 public:
  OswServiceTask(const char* name, uint32_t stackSize, uint32_t sleepTime) : m_taskName(name), m_taskStackSize(stackSize), m_taskSleepTime(sleepTime), m_taskHandle(nullptr) {}
  virtual ~OswServiceTask(){};

  virtual void setup(OswHal* hal) = 0;
  template <typename T>
  void start(OswHal* hal, bool runInBackground = true) {
    this->m_hal = hal;
    if(this->m_taskHandle)
      return;
    xTaskCreatePinnedToCore([](void *pvParameters) -> void {
        delay(2000); // Give the rest of the system some time to start - just in case this service triggers a crash
        T* task = (T*) pvParameters;
        while(true) {
          task->loop();
          delay(task->m_taskSleepTime);
        }
      }, this->m_taskName, this->m_taskStackSize /*stack*/, this /*input*/, 0 /*prio*/,
      &this->m_taskHandle /*handle*/, runInBackground ? 0 : 1);
  }
  virtual void loop();
  virtual void stop();

  OswHal* m_hal;
  const char* m_taskName;
  const uint32_t m_taskStackSize;
  const uint32_t m_taskSleepTime;
 private:
  TaskHandle_t m_taskHandle;
};
#endif