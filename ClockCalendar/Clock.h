#pragma once

namespace utils {

class Clock {
 protected:
  int hour_, minute_, second_, period_;

 public:
  Clock();
  auto readClock(int& hour, int& second, int& minute, int& period) -> void;
};
}  // namespace utils