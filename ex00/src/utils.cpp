#include "../include/utils.hpp"

bool check_format(std::string line) {
  (void)line;
  return true;
}

bool check_date(std::string line) {
  (void)line;
  return true;
}

bool check_value(float value) {
  if (value < 0) {
    std::cout << "Error: not a positive number." << std::endl;
    return false;
  } else if (static_cast<long>(value) > std::numeric_limits<int>::max()) {
    std::cout << "Error: too large a number." << std::endl;
    return false;
  }
  return true;
}