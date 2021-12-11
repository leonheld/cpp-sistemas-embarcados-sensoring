#pragma once

#include "../ClockCalendar/ClockCalendar.h"
#include "Sensor.h"
#include <memory>

namespace sensoring {
class Temperature : public Sensor {
 public:
  Temperature() { this->readSensor(); }
  friend std::ostream& operator<<(std::ostream&, Temperature temperature);

 private:
  auto readSensor() -> void override;
  auto GetRandomNumberForTemperature() -> float;
  std::unique_ptr<ClockCalendar> dateTime_;
};

}  // namespace sensoring