#include "Temperature.h"
#include <random>
#include <string>

namespace {
// Like this one -> https://www.ti.com/lit/ds/symlink/lm35.pdf
const std::string kTemperatureSensorId = "LM35";
}  // namespace

namespace sensoring {
auto Temperature::readSensor() -> void {
  this->setValor(GetRandomNumberForTemperature());
  this->dateTime_->setCalendarNow();
  this->dateTime_->setClockNow();
}
auto Temperature::GetRandomNumberForTemperature() -> float {
  std::random_device random_seed;
  std::mt19937 generator(random_seed());
  // this range is the average minimum and average maximum temperatures for
  // Florianópolis :)
  std::uniform_real_distribution<float> distribution(16.0, 28.0);
  return static_cast<float>(distribution(generator));
}

std::ostream& operator<<(std::ostream& os, Temperature temperature) {
  os << temperature.getValor();
  return os;
}
}  // namespace sensoring
