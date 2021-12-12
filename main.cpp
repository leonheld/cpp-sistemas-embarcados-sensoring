//#include "Registry/PressureRegistry.h"
#include "Registry/TemperatureRegistry.h"
#include <iostream>
#include <memory>

int main() {
  auto temperature_registry =
      std::make_unique<sensoring::TemperatureRegistry>();

  // auto pressure_registry =
  // std::make_unique<sensoring::PressureRegistry>();

  enum MENU_STATES {
    kReadTemperature = 1,
    kDeleteTemperature,
    kConsultTemperature,
    kListTemperatures,
    // kGetTemperatureSensorId,
    kReadPressure,
    kDeletePressure,
    kConsultPressure,
    kListPressures,
    // kGetPressureSensorId,
  };
  std::cout << "1. Read and save temperature." << std::endl
            << "2. Delete a given temperature." << std::endl
            << "3. Consult a given temperature." << std::endl
            << "4. List all temperatures." << std::endl
            << "5. Consult the temperature sensor id attached."
            << "6. Read and save pressure." << std::endl
            << "7. Delete a given pressure." << std::endl
            << "8. Consult a given pressure." << std::endl
            << "9. List all pressures." << std::endl
            << "10. Consult the pressure sensor id attached." << std::endl;

  int option = -1;
  while (1) {
    std::cin >> option;
    switch (option) {
        /*
      case MENU_STATES::READ_PRESSURE:
        pressure_registry->ReadAndSaveCurrentPressure();
        break;

      case MENU_STATES::DELETE_PRESSURE:
        pressure_registry->DeletePressure();
        break;

      case MENU_STATES::CONSULT_PRESSURE:
        pressure_registry->ConsultPressure();
        break;

      case MENU_STATES::LIST_PRESSURES:
        pressure_registry->ListPressures();
        break;

  */
      case MENU_STATES::kReadTemperature:
        std::cout << "Reading and saving current temperature." << std::endl;
        temperature_registry->ReadAndSave();
        break;

      case MENU_STATES::kDeleteTemperature:
        temperature_registry->DeleteEntry();
        break;
        /*
                    case MENU_STATES::CONSULT_TEMPERATURE:
                      temperature_registry->ConsultTemperature();
                      break;
                */
      case MENU_STATES::kListTemperatures:
        std::cout << "Listing all temperatures." << std::endl;
        temperature_registry->List();
        break;

      default:
        std::cout << "Choose a valid option :)" << std::endl;
        break;
    }
  }
  return 0;
}
