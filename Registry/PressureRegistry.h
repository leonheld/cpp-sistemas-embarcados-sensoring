#pragma once

#include "../Pressure/Pressure.h"
#include "../Vector/Vector.h"
#include "Registry.h"

namespace sensoring {
class PressureRegistry : public Registry {
 public:
  PressureRegistry() = default;
  auto ReadAndSave() -> void override;
  auto List() -> void override;
  auto Delete() -> void override;
  auto Consult() -> void override;
  auto Peek(unsigned int index) -> Pressure;
  auto filterAndPrintAboveDate(int day, int month, int year) -> void;
  auto filterAndPrintBelowDate(int day, int month, int year) -> void;

 private:
  utils::Vector<Pressure> readings_ = utils::Vector<Pressure>();
  void filterAndPrintAboveMagnitude(int magnitude);
  void filterAndPrintBelowMagnitude(int magnitude);
};
}  // namespace sensoring