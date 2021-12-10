cmake_minimum_required(VERSION 3.16)
project(playground)

set(CMAKE_CXX_STANDARD 20)

include_directories(third_party/Sensor)
include_directories(Temperature)

add_executable(sensoring main.cpp third_party/Sensor/Sensor.cpp third_party/Sensor/Sensor.h Temperature/Temperature.cpp Temperature/Temperature.h Pressure/Pressure.cpp Pressure/Pressure.h ClockCalendar/ClockCalendar.cpp ClockCalendar/ClockCalendar.h Vector/Vector.h)
