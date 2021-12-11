#include "Clock.h"
#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

namespace utils {
auto Clock::readClock(int& hour, int& second, int& minute, int& period)
    -> void {
  hour = hour_;
  second = second_;
  minute = minute_;
  period = period_;
}
Clock::Clock() {
  // nothing makes me happier than std::chrono. Maybe std::fmt will.
  using namespace std::chrono;

  auto now = system_clock::now();
  auto timer = system_clock::to_time_t(now);
  std::tm bt = *std::localtime(&timer);
  std::stringstream hour;
  std::stringstream minute;
  std::stringstream second;

  hour << std::put_time(&bt, "%H");
  minute << std::put_time(&bt, "%M");
  second << std::put_time(&bt, "%S");

  hour_ = std::stoi(hour.str());
  minute_ = std::stoi(minute.str());
  second_ = std::stoi(second.str());
}

}  // namespace utils