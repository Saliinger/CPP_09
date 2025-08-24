#include "../include/RPN.hpp"

int main(int ac, char **av) {
  if (ac > 3) {
    RPN a(av);
  } else {
    throw std::runtime_error("Error: wrong usage");
    return 1;
  }
  return 0;
}