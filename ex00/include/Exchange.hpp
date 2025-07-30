#pragma once

#include <iostream>
#include <map>
#include <fstream>
#include <cstring>

#define DATA_PATH "../data/data.csv";

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

  // 1 check data
  bool check_data();
  // 2 check input data
  bool check_input();
  // 3 make the output
  void show();

 private:
  std::map<std::string, float> _records;
};