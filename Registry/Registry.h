#pragma once
#include "../Sensor/Sensor.h"

namespace sensoring {
class Registry {
 public:
  virtual ~Registry() = default;
  virtual auto ReadAndSaveCurrent() -> void = 0;
  virtual auto List() -> void = 0;

  /*
  virtual auto Delete() -> void = 0;
  virtual auto Consult() -> Sensor = 0;
   */
};
}  // namespace sensoring