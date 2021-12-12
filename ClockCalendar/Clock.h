#pragma once

namespace utils {

class Clock {
 protected:
  int hour_, minute_, second_;

 public:
  Clock() {
    hour_ = 0;
    minute_ = 0;
    second_ = 0;
  };
  auto setClockNow() -> void;
  auto readClock(int& hour, int& second, int& minute) -> void;
};
}  // namespace utils