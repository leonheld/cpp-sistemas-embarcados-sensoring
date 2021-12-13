#include "Temperature.h"
#include <random>
#include <string>

namespace {
// just a random number for a given sensor.
const int kTemperatureSensorId = 1;
}  // namespace

namespace sensoring {

Temperature::Temperature() {
  dateTime_ = std::make_shared<utils::ClockCalendar>();
}

auto Temperature::newRead() -> void {
  this->setID(kTemperatureSensorId);
  this->readSensor();
}

auto Temperature::readSensor() -> void {
  this->setValor(GetRandomNumberForTemperature());
  this->dateTime_->CalendarNow();
  this->dateTime_->ClockNow();
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
auto Temperature::prettyPrint() -> void {
  std::cout << " Temperature gotten at " << this->timestamp() << " from sensor "
            << this->getID() << " is " << this->getValor() << "º Celsius."
            << std::endl;
}
bool Temperature::wasDoneBefore(int day, int month, int year) {
  dateTime_->day();

  return dateTime_->year() < year && dateTime_->month() < month &&
         dateTime_->day() < day;
}
bool Temperature::readingBelow(int magnitude) {
  return magnitude > this->getValor();
}
}  // namespace sensoring
