#include "Clock.h"
#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

namespace utils {
auto Clock::readClock(int& hour, int& second, int& minute) -> void {
  hour = hour_;
  second = second_;
  minute = minute_;
}

auto Clock::setClockNow() -> void {  // nothing makes me happier than
                                     // std::chrono. Maybe std::fmt will.
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

  this->hour_ = std::stoi(hour.str());
  this->minute_ = std::stoi(minute.str());
  this->second_ = std::stoi(second.str());
}

}  // namespace utils