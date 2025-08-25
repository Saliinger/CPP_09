 #include "../include/utils.hpp"

bool check_format(std::string line) {
  (void)line;
  // format yyyy-mm-dd | value
  return true;
}

bool check_date(std::string line) {
  (void)line;
  // check month and days and years
  return true;
}

bool check_value(float value) {
  if (value < 0) {
    std::cout << "Error: not a positive number." << std::endl;
    return false;
  } else if (value > 21000000) {
    std::cout << "Error: too large a number." << std::endl;
    return false;
  }
  return true;
}