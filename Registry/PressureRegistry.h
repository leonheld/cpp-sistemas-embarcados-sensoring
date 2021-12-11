#pragma once
#include "../Pressure/Pressure.h"
#include "../Vector/Vector.h"
namespace sensoring {
class PressureRegistry {
 private:
  utils::Vector<Pressure> readings;
};
}  // namespace sensoring