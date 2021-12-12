#pragma once

#include "../ClockCalendar/ClockCalendar.h"
#include "Sensor.h"
#include <memory>

namespace sensoring {
class Temperature : public Sensor {
 public:
  Temperature();
  friend std::ostream& operator<<(std::ostream&, Temperature temperature);

  auto timestamp() -> std::string { return dateTime_->GenerateTimestamp(); }

  auto prettyPrint() -> void;

  auto newRead() -> void;

  bool wasDoneBefore(int day, int month, int year);

 private:
  auto readSensor() -> void override;
  static auto GetRandomNumberForTemperature() -> float;
  std::shared_ptr<utils::ClockCalendar> dateTime_;
};

}  // namespace sensoring