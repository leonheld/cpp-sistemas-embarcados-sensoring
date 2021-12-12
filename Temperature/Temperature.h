#pragma once

#include "../ClockCalendar/ClockCalendar.h"
#include "Sensor.h"
#include <memory>

namespace sensoring {
class Temperature : public Sensor {
 public:
  Temperature() {
    dateTime_ = std::make_shared<utils::ClockCalendar>();
    this->readSensor();
  }
  friend std::ostream& operator<<(std::ostream&, Temperature temperature);

  auto timestamp() -> std::string { return dateTime_->getTimestamp(); }

 private:
  auto readSensor() -> void override;
  static auto GetRandomNumberForTemperature() -> float;
  std::shared_ptr<utils::ClockCalendar> dateTime_;
};

}  // namespace sensoring