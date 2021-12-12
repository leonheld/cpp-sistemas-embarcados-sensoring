#include "Calendar.h"
#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

namespace utils {
auto Calendar::readCalendar(int& month, int& day, int& year) -> void {
  month = month_;
  day = day_;
  year = year_;
}
auto Calendar::setCalendarNow() -> void {
  using namespace std::chrono;

  auto now = system_clock::now();
  auto timer = system_clock::to_time_t(now);
  std::tm bt = *std::localtime(&timer);
  std::stringstream month;
  std::stringstream day;
  std::stringstream year;

  month << std::put_time(&bt, "%m");
  day << std::put_time(&bt, "%d");
  year << std::put_time(&bt, "%Y");

  month_ = std::stoi(month.str());
  day_ = std::stoi(day.str());
  year_ = std::stoi(year.str());
}
}  // namespace utils