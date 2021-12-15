cmake_minimum_required(VERSION 3.16)
project(playground)

set(CMAKE_CXX_STANDARD 20)

include_directories(third_party/Sensor)
include_directories(Temperature)

add_executable(sensoring main.cpp third_party/Sensor/Sensor.cpp third_party/Sensor/Sensor.h Temperature/Temperature.cpp Temperature/Temperature.h Pressure/Pressure.cpp Pressure/Pressure.h ClockCalendar/ClockCalendar.cpp ClockCalendar/ClockCalendar.h Vector/Vector.h ClockCalendar/Clock.cpp ClockCalendar/Clock.h ClockCalendar/Calendar.cpp ClockCalendar/Calendar.h Registry/TemperatureRegistry.cpp Registry/TemperatureRegistry.h Registry/PressureRegistry.cpp Registry/PressureRegistry.h Registry/Registry.h)
#add_executable(sensoring main.cpp third_party/Sensor/Sensor.cpp third_party/Sensor/Sensor.h Temperature/Temperature.cpp Temperature/Temperature.h Vector/Vector.h Registry/TemperatureRegistry.cpp Registry/TemperatureRegistry.h Registry/Registry.h)
