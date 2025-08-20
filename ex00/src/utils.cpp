#include "../include/utils.hpp"

#include <cstdlib>
#include <sstream>

bool check_date(std::string &line) {
  // Check if line has exactly 10 characters (YYYY-MM-DD)
  if (line.length() != 10) return false;

  // Check if dashes are in correct positions
  if (line[4] != '-' || line[7] != '-') return false;

  // Extract year, month, day
  std::string year = line.substr(0, 4);
  std::string month = line.substr(5, 2);
  std::string day = line.substr(8, 2);

  // Check if all characters are digits
  for (int i = 0; i < 4; i++) {
    if (!std::isdigit(year[i])) return false;
  }
  for (int i = 0; i < 2; i++) {
    if (!std::isdigit(month[i]) || !std::isdigit(day[i])) return false;
  }

  // Convert to integers for range checking
  int y = std::atoi(year.c_str());
  int m = std::atoi(month.c_str());
  int d = std::atoi(day.c_str());

  // Basic range checks
  if (y < 1000 || y > 9999)  // reasonable year range
    return false;
  if (m < 1 || m > 12)  // month range
    return false;
  if (d < 1 || d > 31)  // day range (basic check)
    return false;

  // More detailed day validation based on month
  if (m == 2) {  // February
    bool isLeap = (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    if (d > (isLeap ? 29 : 28)) return false;
  } else if (m == 4 || m == 6 || m == 9 ||
             m == 11) {  // April, June, September, November
    if (d > 30) return false;
  }

  return true;
}