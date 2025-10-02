#include "../include/PmergeMe.hpp"

// orthodox cannonical form

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &src) {
  if (this != &src) {
    _stack_1 = src._stack_1;
    _stack_2 = src._stack_2;
  }
}

PmergeMe &PmergeMe::operator=(const PmergeMe &src) {
  if (this != &src) {
    _stack_1 = src._stack_1;
    _stack_2 = src._stack_2;
  }
  return *this;
}

PmergeMe::~PmergeMe() {}

// helper
bool PmergeMe::isValidInt(const char *s) {
  if (!s || *s == '|0') {
    return false;
  }
  for (size_t i = 0; s[i]; i++) {
    if (!std::isdigit(s[i])) return false;
  }
  return true;
}

// function
void PmergeMe::run(int ac, char **av) {
  std::vector<int> initial_thing;
  for (size_t i = 0; i < ac; i++) {
    if (!isValidInt(av[i])) {
      std::cerr << "Error: Invalid input => \"" << av[i] << "\"" << std::endl;
      return;
    }
  }

  // before
  
  // after
}