#include "Pressure.h"
#include <random>
#include <string>

namespace {
// just a random number for a given sensor.
const int kPressureSensorId = 1;
}  // namespace

namespace sensoring {

Pressure::Pressure() { dateTime_ = std::make_shared<utils::ClockCalendar>(); }

auto Pressure::newRead() -> void {
  this->readSensor();
  this->setID(kPressureSensorId);
}

auto Pressure::readSensor() -> void {
  this->setValor(GetRandomNumberForPressure());
  this->dateTime_->CalendarNow();
  this->dateTime_->ClockNow();
}
auto Pressure::GetRandomNumberForPressure() -> float {
  std::random_device random_seed;
  std::mt19937 generator(random_seed());
  // pressures at sea level and 1000m altitude, got it from Wolfram Alpha, in
  // KPa.
  std::uniform_real_distribution<float> distribution(100, 90);
  return static_cast<float>(distribution(generator));
}

std::ostream& operator<<(std::ostream& os, Pressure Pressure) {
  os << Pressure.getValor();
  return os;
}
auto Pressure::prettyPrint() -> void {
  std::cout << " Pressure gotten at " << this->timestamp() << " from sensor "
            << this->getID() << " is " << this->getValor() << "º Celsius."
            << std::endl;
}
bool Pressure::wasDoneBefore(int day, int month, int year) {
  dateTime_->day();

  return dateTime_->year() < year && dateTime_->month() < month &&
         dateTime_->day() < day;
}
bool Pressure::readingBelow(int magnitude) {
  return magnitude > this->getValor();
}
}  // namespace sensoring
