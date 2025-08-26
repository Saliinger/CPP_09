#pragma once

#include <deque>
#include <iostream>
#include <vector>

class PmergeMe {
 public:
  // orthodox cannonical form
  PmergeMe();
  PmergeMe(const PmergeMe &src);
  PmergeMe &operator=(const PmergeMe &src);
  ~PmergeMe();

 private:
  std::vector<int> _stack_1;
  std::deque<int> _stack_2;
};
