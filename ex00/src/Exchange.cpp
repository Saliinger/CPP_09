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
    std::string year = date.substr(0, 4);
    std::string month = date.substr(5, 2);
    std::string day = date.substr(8, 2);
    unsigned int date_int = std::atoi(year.c_str()) * 10000 +

                            std::atoi(month.c_str()) * 100 +
                            std::atoi(day.c_str());
    _records.insert(
        std::pair<unsigned int, float>(date_int, std::atof(s_value.c_str())));
  }

  // close the data file
  fin.close();
}

// function

void Exchange::complete(const std::string &file) const {
  // read each line see if good then search closest price then display
  std::ifstream fin;
  std::string line, date, unit;

  std::map<unsigned int, float>::const_iterator it, ite;

  it = _records.begin();
  ite = _records.end();

  fin.open(file.c_str());

  if (!fin.is_open()) throw std::runtime_error("Error: could not open file.");

  while (std::getline(fin, line)) {
    if (!check_format(line)) {
      std::cout << "Error: wrong format" << std::endl;
    } else if (!check_date(line)) {
      std::cout << "Error: wrong format" << std::endl;
    } else {
      std::string year = date.substr(0, 4);
      std::string month = date.substr(5, 2);
      std::string day = date.substr(8, 2);

      unsigned int date_int = std::atoi(year.c_str()) * 10000 +
                              std::atoi(month.c_str()) * 100 +
                              std::atoi(day.c_str());

      std::map<unsigned int, float>::const_iterator value =
          _records.lower_bound(date_int);

      // display: 2011-01-03 => 1.2 = 0.36
      std::cout << value->first << " => " << value->second << " = "
                << value->second * 1 << std::endl;
    }
  }
  fin.close();
}

void Exchange::show() {
  std::map<unsigned int, float>::iterator it, ite;

  it = _records.begin();
  ite = _records.end();

  while (it != ite) {
    std::cout << it->first << ", " << it->second << std::endl;
    it++;
  }
}
