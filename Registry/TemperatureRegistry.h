#pragma once

//#include "../ClockCalendar/ClockCalendar.h"
#include "../Vector/Vector.h"
#include "Registry.h"
#include "Temperature.h"

namespace sensoring {
class TemperatureRegistry : public Registry {
 public:
  auto ReadAndSaveCurrent() -> void override;
  auto List() -> void override;
  auto number_of_elements() const -> int { return number_of_elements_; }
  auto one_more_element() -> void { number_of_elements_++; }
  /*
  auto Delete() -> void override;
  auto Consult() -> Sensor override;
*/
 private:
  utils::Vector<Temperature> readings_ = utils::Vector<Temperature>(20);
  int number_of_elements_ = 0;
};
}  // namespace sensoring