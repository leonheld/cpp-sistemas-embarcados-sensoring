#pragma once

#include <iostream>
namespace utils {
class Calendar {
 protected:
  int month_;
  int day_;
  int year_;

 public:
  Calendar() {
    month_ = 0;
    day_ = 0;
    year_ = 0;
  }
  auto CalendarNow() -> void;
};
}  // namespace utils