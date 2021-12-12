#include "TemperatureRegistry.h"

namespace sensoring {

auto TemperatureRegistry::ReadAndSave() -> void {
  auto current_temperature = new Temperature();
  current_temperature->newRead();
  readings_.push_back(*current_temperature);
}

auto TemperatureRegistry::List() -> void {
  for (int i = 0; i < this->readings_.number_of_elements(); ++i) {
    std::cout << i << ".";
    readings_[i].prettyPrint();
  }
}

auto TemperatureRegistry::DeleteEntry() -> void {
  std::cout << "Which temperature entry to delete?" << std::endl;
  this->List();

  int entry;
  std::cin >> entry;

  std::cout << "Removing the following entry: " << std::endl
            << Peek(entry) << std::endl;

  std::cout << "Are you sure? You cannot undo this operation." << std::endl
            << "Type y or n" << std::endl;

  std::string choice;
  std::cin >> choice;

  if (choice == std::string("y")) readings_.remove_at(entry);

  std::cout << "Done!" << std::endl;
}
auto TemperatureRegistry::Consult() -> void {
  std::cout
      << "There are three consulting options: " << std::endl
      << "1. Consult all readings below a certain integer temperature."
      << std::endl
      << "2. Consult all readings above a certain integer temperature."
      << std::endl
      << "3. Consult all readings below a certain date (day/month/year format)."
      << std::endl
      << "4. Consult all readings above a certain date (day/month/year format)."
      << std::endl;

  enum CONSULT_STATES {
    kReadingsBelowMagnitudeThreshold = 1,
    kReadingsAboveMagnitudeThreshold,
    kReadingsBelowDateThreshold,
    kReadingsAboveDateThreshold
  };

  int option = -1;
  std::cout << "Choose an option." << std::endl;
  std::cin >> option;

  std::string date_option;
  int magnitude_option;
  switch (option) {
    case CONSULT_STATES::kReadingsAboveDateThreshold:
      std::cout << "Chose option 1. Type date in the day/month/year format to "
                   "search for readings above such date."
                << std::endl;
      std::cin >> date_option;
      // FIXME(ljh): implement
      // this->filterAndPrintBelowDate(date_option);
      break;

    case CONSULT_STATES::kReadingsBelowDateThreshold:
      std::cout << "Chose option 2. Type date in the day/month/year format to "
                   "search for readings above such date."
                << std::endl;
      std::cin >> date_option;
      // FIXME(ljh): implement
      // this->filterAndPrintBelowDate(date_option);
      break;

    case CONSULT_STATES::kReadingsAboveMagnitudeThreshold:
      std::cout << "Chose option 3. Type reading magnitude (just the number) "
                   "to search for readings above such magnitude."
                << std::endl;
      std::cin >> magnitude_option;
      // FIXME(ljh): implement
      // this->filterAndPrintAboveMagnitude(magnitude_option);
      break;

    case CONSULT_STATES::kReadingsBelowMagnitudeThreshold:
      std::cout << "Chose option 4. Type reading magnitude (just the number) "
                   "to search for readings below such magnitude."
                << std::endl;
      std::cin >> magnitude_option;
      // FIXME(ljh): implement
      // this->filterAndPrintBelowMagnitude(magnitude_option);
      break;

    default:
      std::cout << "Choose a valid option :)" << std::endl;
      break;
  }
}
auto TemperatureRegistry::Peek(unsigned int index) -> Temperature {
  return readings_[index];
}
}  // namespace sensoring