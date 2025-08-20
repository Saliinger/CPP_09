#pragma once

#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>

#define DATA_PATH "./data/data.csv"

class Exchange {
 public:
  // orthodox cannonical form
  Exchange();
  Exchange(const Exchange &src);
  Exchange &operator=(const Exchange &src);
  ~Exchange();

  // add Data/Input
  Exchange(std::string data_path);

  // function
  void complete(const std::string &file) const;

  void show();

 private:
  std::map<int, int, int, float> _records;
};