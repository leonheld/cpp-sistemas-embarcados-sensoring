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
  auto ClockNow() -> void;
};
}  // namespace utils