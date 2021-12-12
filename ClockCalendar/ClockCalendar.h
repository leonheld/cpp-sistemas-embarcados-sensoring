#pragma once

#include "Calendar.h"
#include "Clock.h"
#include <string>

namespace utils {
class ClockCalendar : public Calendar, public Clock {
 public:
  auto GenerateTimestamp() -> std::string;
  auto day() const { return day_; }
  auto month() const { return month_; }
  auto year() const { return year_; }
  auto hour() const { return hour_; }
  auto minute() const { return minute_; }
  auto second() const { return second_; }
};
}  // namespace utils