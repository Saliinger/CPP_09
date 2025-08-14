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
    _records.insert({date, std::atof(s_value.c_str())});
  }

  // close the data file
  fin.close();
}

// function

void Exchange::show() {
    std::map<std::string, float>::iterator it, ite;

    it = _records.begin();
    ite = _records.end();

    while (it != ite)
    {
        std::cout << it->first << ", " << it->second << std::endl;
        it++;
    }
    
}
