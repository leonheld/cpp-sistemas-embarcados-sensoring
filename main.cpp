#include "Registry/PressureRegistry.h"
#include "Registry/TemperatureRegistry.h"
#include <iostream>
#include <memory>

int main() {
  auto temperature_registry =
      std::make_unique<sensoring::TemperatureRegistry>();

  auto pressure_registry = std::make_unique<sensoring::PressureRegistry>();

  enum MENU_STATES {
    kReadTemperature = 1,
    kDeleteTemperature,
    kConsultTemperature,
    kListTemperatures,
    kReadPressure,
    kDeletePressure,
    kConsultPressure,
    kListPressures,
  };

  int option = -1;
  while (1) {
    std::cout << "__________ MENU __________" << std::endl
              << "1. Read and save temperature." << std::endl
              << "2. Delete a given temperature." << std::endl
              << "3. Consult a given temperature." << std::endl
              << "4. List all temperatures." << std::endl
              << "5. Read and save pressure." << std::endl
              << "6. Delete a given pressure." << std::endl
              << "7. Consult a given pressure." << std::endl
              << "8. List all pressures." << std::endl;

    std::cin >> option;
    switch (option) {
      case MENU_STATES::kReadTemperature:
        std::cout << "Reading and saving current temperature." << std::endl;
        temperature_registry->ReadAndSave();
        break;

      case MENU_STATES::kDeleteTemperature:
        temperature_registry->Delete();
        break;

      case MENU_STATES::kConsultTemperature:
        temperature_registry->Consult();
        break;

      case MENU_STATES::kListTemperatures:
        std::cout << "Listing all temperatures." << std::endl;
        temperature_registry->List();
        break;

      case MENU_STATES::kReadPressure:
        std::cout << "Reading and saving current pressure." << std::endl;
        pressure_registry->ReadAndSave();
        break;

      case MENU_STATES::kDeletePressure:
        pressure_registry->Delete();
        break;

      case MENU_STATES::kConsultPressure:
        pressure_registry->Consult();
        break;

      case MENU_STATES::kListPressures:
        std::cout << "Listing all temperatures." << std::endl;
        pressure_registry->List();
        break;

      default:
        std::cout << "Choose a valid option :)" << std::endl;
        break;
    }
  }
  return 0;
}
