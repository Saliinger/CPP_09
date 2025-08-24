#pragma once

#include <iostream>
#include <vector>

class RPN {
 public:
  // orthodox cannonical form
  RPN();
  RPN(const RPN &src);
  RPN &operator=(const RPN &src);
  ~RPN();

  // other constructor
  RPN(char **av);

  // debug
  void show(char c) const;

 private:
  std::vector<int> _storage;
};