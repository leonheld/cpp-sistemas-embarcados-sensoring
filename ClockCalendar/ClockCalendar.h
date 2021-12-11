#pragma once

#include "Calendar.h"
#include "Clock.h"
namespace utils {
class ClockCalendar : public Calendar, public Clock {
 public:
  auto getTimestamp() -> void;
};
}  // namespace utils