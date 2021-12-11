#pragma once

namespace utils {
class Calendar {
 private:
  int month_;
  int day_;
  int year_;

 public:
  Calendar();
  void readCalendar(int& month, int& day, int& year);
};
}  // namespace utils