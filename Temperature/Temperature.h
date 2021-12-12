#pragma once

#include "../ClockCalendar/ClockCalendar.h"
#include "Sensor.h"
#include <memory>

namespace sensoring {
class Temperature : public Sensor {
 public:

  Temperature();
  friend std::ostream& operator<<(std::ostream&, Temperature temperature);

  auto timestamp() -> std::string { return dateTime_->getTimestamp(); }

  auto prettyPrint() -> void;

  auto newRead() -> void;

 private:
  auto readSensor() -> void override;
  static auto GetRandomNumberForTemperature() -> float;
  std::shared_ptr<utils::ClockCalendar> dateTime_;
};

}  // namespace sensoring