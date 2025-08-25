#include "../include/utils.hpp"

bool check_format(std::string &line) { return true; }

bool check_date(std::string &line) { return true; }

bool check_value(int value) {
  if (value < 0) return false;
  return true;
}