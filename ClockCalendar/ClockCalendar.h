#pragma once

#include "Calendar.h"
#include "Clock.h"
#include <string>

namespace utils {
class ClockCalendar : public Calendar, public Clock {
 public:
  auto getTimestamp() -> std::string;
};
}  // namespace utils