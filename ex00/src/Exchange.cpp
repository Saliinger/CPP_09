#include "../include/Exchange.hpp"

// orthodox cannonical form
Exchange::Exchange() {}

Exchange::Exchange(const Exchange &src) { _records = src._records; }

Exchange &Exchange::operator=(const Exchange &src) {
  if (this != &src) {
    _records = src._records;
  }
  return *this;
}

Exchange::~Exchange() {}

// other constructor
Exchange::Exchange(std::string data_path) {
  std::ifstream fin;

  // open the data file
  fin.open(data_path.c_str());

  std::string date, s_value;

  // pass the first line
  std::getline(fin, date);

  // loop into the file
  while (std::getline(fin, date, ',') && std::getline(fin, s_value)) {
    _records.insert(
        std::pair<std::string, float>(date, std::atof(s_value.c_str())));
  }

  // close the data file
  fin.close();
}

// function

void Exchange::complete(const std::string &file) const {
  std::ifstream fin;
  std::string line, date, unit;
  std::map<std::string, float>::const_iterator it, ite;

  it = _records.begin();
  ite = _records.end();
  fin.open(file.c_str());

  if (!fin.is_open()) throw std::runtime_error("Error: could not open file.");

  std::getline(fin, line);
  while (std::getline(fin, date, '|') && std::getline(fin, unit)) {
    if (!check_format(line)) {
      std::cout << "Error: wrong format" << std::endl;
    } else if (!check_date(line)) {
      std::cout << "Error: wrong format" << std::endl;
    } else {
      std::map<std::string, float>::const_iterator record_value =
          _records.lower_bound(date);

      float num = std::atol(unit.c_str());
      if (check_value(num))
        // display: 2011-01-03 => 1.2 = 0.36
        std::cout << record_value->first << " => " << record_value->second
                  << " = " << record_value->second * num << std::endl;
    }
  }
  fin.close();
}
