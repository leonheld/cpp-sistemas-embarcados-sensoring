#pragma once

#include "../Vector/Vector.h"
#include "Registry.h"
#include "Temperature.h"

namespace sensoring {
class TemperatureRegistry : public Registry {
 public:
  TemperatureRegistry() = default;
  auto ReadAndSave() -> void override;
  auto List() -> void override;
  auto Delete() -> void override;
  auto Consult() -> void override;
  auto Peek(unsigned int index) -> Temperature;
  auto filterAndPrintAboveDate(int day, int month, int year) -> void;
  auto filterAndPrintBelowDate(int day, int month, int year) -> void;

 private:
  utils::Vector<Temperature> readings_ = utils::Vector<Temperature>();
  void filterAndPrintAboveMagnitude(int magnitude);
  void filterAndPrintBelowMagnitude(int magnitude);
};
}  // namespace sensoring