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

// other constructor

// PmergeMe::PmergeMe()

// function