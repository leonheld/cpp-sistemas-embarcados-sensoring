#include "TemperatureRegistry.h"

namespace {
auto kMaxReadings = 100;
}

namespace sensoring {

auto TemperatureRegistry::ReadAndSaveCurrent() -> void {
  auto current_temperature = new Temperature();
  this->one_more_element();
  readings_.push_back(*current_temperature);
}

auto TemperatureRegistry::List() -> void {
  std::string timestamp;
  Temperature temp;
  for (int i = 0; i < this->number_of_elements(); ++i) {
    // this readings_[i] call actually uses the overloaded << operator.
    temp = readings_[i];
    std::cout << "Temperature gotten at " << temp.timestamp() + " is " << temp
              << "º Celsius." << std::endl;
  }
}

/*
auto TemperatureRegistry::Delete() -> void {}
auto TemperatureRegistry::Consult() -> Sensor {}
 */
}  // namespace sensoring