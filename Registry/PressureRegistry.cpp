#include "PressureRegistry.h"

namespace sensoring {

auto PressureRegistry::ReadAndSave() -> void {
  auto current_pressure = new Pressure();
  current_pressure->newRead();
  readings_.push_back(*current_pressure);
  if (!current_pressure->readingBelow(60)) {
    this->valid_.push_back(false);
    return;
  }
  this->valid_.push_back(true);
}

auto PressureRegistry::List() -> void {
  for (int i = 0; i < this->readings_.number_of_elements(); ++i) {
    std::cout << i << ".";
    readings_[i].prettyPrint();
  }
}

auto PressureRegistry::Delete() -> void {
  std::cout << "Which Pressure entry to delete?" << std::endl;
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
auto PressureRegistry::Consult() -> void {
  std::cout
      << "There are three consulting options: " << std::endl
      << "1. Consult all readings above a certain date (day/month/year format)."
      << std::endl
      << "2. Consult all readings below a certain date (day/month/year format)."
      << std::endl
      << "3. Consult all readings above a certain integer Pressure."
      << std::endl
      << "4. Consult all readings below a certain integer Pressure."
      << std::endl;

  enum CONSULT_STATES {
    kReadingsAboveDateThreshold = 1,
    kReadingsBelowDateThreshold,
    kReadingsAboveMagnitudeThreshold,
    kReadingsBelowMagnitudeThreshold
  };

  int option = -1;
  std::cout << "Choose an option." << std::endl;
  std::cin >> option;

  int day;
  int month;
  int year;

  int magnitude_option;
  switch (option) {
    case CONSULT_STATES::kReadingsAboveDateThreshold:
      std::cout << "Chose option 1. Type the day/month/year to search for "
                   "readings above such date."
                << std::endl;

      std::cout << "Type in day: " << std::endl;
      std::cin >> day;
      std::cout << "Type in month: " << std::endl;
      std::cin >> month;
      std::cout << "Type in year: " << std::endl;
      std::cin >> year;

      this->filterAndPrintAboveDate(day, month, year);
      break;

    case CONSULT_STATES::kReadingsBelowDateThreshold:
      std::cout << "Chose option 2. Type the day/month/year to search for "
                   "readings above such date."
                << std::endl;

      std::cout << "Type in day: " << std::endl;
      std::cin >> day;
      std::cout << "Type in month: " << std::endl;
      std::cin >> month;
      std::cout << "Type in year: " << std::endl;
      std::cin >> year;

      this->filterAndPrintBelowDate(day, month, year);
      break;

    case CONSULT_STATES::kReadingsAboveMagnitudeThreshold:
      std::cout << "Chose option 3. Type reading magnitude (just the number) "
                   "to search for readings above such magnitude."
                << std::endl;
      std::cin >> magnitude_option;
      this->filterAndPrintAboveMagnitude(magnitude_option);
      break;

    case CONSULT_STATES::kReadingsBelowMagnitudeThreshold:
      std::cout << "Chose option 4. Type reading magnitude (just the number) "
                   "to search for readings below such magnitude."
                << std::endl;
      std::cin >> magnitude_option;
      this->filterAndPrintBelowMagnitude(magnitude_option);
      break;

    default:
      std::cout << "Choose a valid option :)" << std::endl;
      break;
  }
}
auto PressureRegistry::Peek(unsigned int index) -> Pressure {
  return readings_[index];
}

auto PressureRegistry::filterAndPrintAboveDate(int day, int month, int year)
    -> void {
  std::cout << "The following readings were done after " << day << "/" << month
            << "/" << year << std::endl;

  for (int i = 0; i < readings_.number_of_elements(); ++i) {
    if (!readings_[i].wasDoneBefore(day, month, year)) {
      readings_[i].prettyPrint();
    }
  }
}

auto PressureRegistry::filterAndPrintBelowDate(int day, int month, int year)
    -> void {
  std::cout << "The following readings were done before " << day << "/" << month
            << "/" << year << std::endl;

  for (int i = 0; i < readings_.number_of_elements(); ++i) {
    if (readings_[i].wasDoneBefore(day, month, year)) {
      readings_[i].prettyPrint();
    }
  }
}
void PressureRegistry::filterAndPrintAboveMagnitude(int magnitude) {
  std::cout << "Listing all reads above " << magnitude << "º Celsius"
            << std::endl;
  for (int i = 0; i < readings_.number_of_elements(); ++i) {
    if (!readings_[i].readingBelow(magnitude)) {
      readings_[i].prettyPrint();
    }
  }
}

void PressureRegistry::filterAndPrintBelowMagnitude(int magnitude) {
  std::cout << "Listing all reads below " << magnitude << "º Celsius"
            << std::endl;
  for (int i = 0; i < readings_.number_of_elements(); ++i) {
    if (readings_[i].readingBelow(magnitude)) {
      readings_[i].prettyPrint();
    }
  }
}

}  // namespace sensoring