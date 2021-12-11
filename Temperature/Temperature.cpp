#include "Temperature.h"
#include <iostream>
#include <random>
#include <string>

namespace {
// Like this one -> https://www.ti.com/lit/ds/symlink/lm35.pdf
std::string kTemperatureSensorId = "LM35";
}  // namespace

namespace sensoring {
auto Temperature::readSensor() -> void {
  this->setValor(GetRandomNumberForTemperature());
  this->dateTime_->getTimestamp();
}
auto Temperature::GetRandomNumberForTemperature() -> float {
  std::random_device random_seed;
  std::mt19937 generator(random_seed());
  // this range is the average minimum and average maximum temperatures for
  // Florianópolis :)
  std::uniform_real_distribution<float> distribution(16.0, 28.0);

  // Casting just for added safety. Compiler will prob optimize it away if not
  // needed.
  return static_cast<float>(distribution(generator));
}
std::ostream& operator<<(std::ostream& os, Temperature temperature) {
  os << temperature.getValor();
  return os;
}
}  // namespace sensoring
