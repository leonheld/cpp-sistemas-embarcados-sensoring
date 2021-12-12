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
  auto DeleteEntry() -> void;
  auto Consult() -> void override;
  auto Peek(unsigned int index) -> Temperature;

 private:
  utils::Vector<Temperature> readings_ = utils::Vector<Temperature>();
};
}  // namespace sensoring