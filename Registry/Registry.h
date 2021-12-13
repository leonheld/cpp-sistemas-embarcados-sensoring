#pragma once
#include "../Sensor/Sensor.h"
#include "../Vector/Vector.h"

namespace sensoring {
class Registry {
 public:
  virtual ~Registry() = default;
  virtual auto ReadAndSave() -> void = 0;
  virtual auto List() -> void = 0;
  virtual auto Consult() -> void = 0;
  virtual auto Delete() -> void = 0;

 private:
  utils::Vector<bool> valid_ = utils::Vector<bool>();
};
}  // namespace sensoring