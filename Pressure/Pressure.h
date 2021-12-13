#pragma once

#include "../ClockCalendar/ClockCalendar.h"
#include "Sensor.h"
#include <memory>

namespace sensoring {
class Pressure : public Sensor {
 public:
  Pressure();
  friend std::ostream& operator<<(std::ostream&, Pressure Pressure);

  auto timestamp() -> std::string { return dateTime_->GenerateTimestamp(); }

  auto prettyPrint() -> void;

  auto newRead() -> void;

  bool wasDoneBefore(int day, int month, int year);

  bool readingBelow(int magnitude);

 private:
  auto readSensor() -> void override;
  static auto GetRandomNumberForPressure() -> float;
  std::shared_ptr<utils::ClockCalendar> dateTime_;
};

}  // namespace sensoring