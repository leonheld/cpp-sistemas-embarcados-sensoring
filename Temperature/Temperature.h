#pragma once

//#include "ClockCalendar.h"
#include "Sensor.h"

namespace sensoring {
class Temperature : public Sensor {
  // ClockCalendar dataHora;

 protected:
  void readSensor();
};
}  // namespace sensoring