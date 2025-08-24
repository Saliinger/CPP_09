#include "../include/RPN.hpp"

// orhtodox cannonical form

RPN::RPN() {}

RPN::RPN(const RPN &src) {
  if (this != &src) {
    _storage = src._storage;
  }
}

RPN &RPN::operator=(const RPN &src) {
  if (this != &src) {
    _storage = src._storage;
  }
  return *this;
}

RPN::~RPN() {}

// other constructor

RPN::RPN(char **av) {
  for (size_t i = 1; av[i]; i++) {
    if (std::atoi(av[i]))
      _storage.push_back(std::atoi(av[i]));
    else {
      std::vector<int>::iterator ite = _storage.end();
      int last = 0, new_last = 0;
      switch (av[i][0]) {
        case '+':
          last = *ite;
          _storage.pop_back();
          ite = _storage.end();
          new_last = *ite;
          _storage.pop_back();
          _storage.push_back(new_last + last);
          show(av[i][0]);
          break;

        case '-':
          last = *ite;
          _storage.pop_back();
          ite = _storage.end();
          new_last = *ite;
          _storage.pop_back();
          _storage.push_back(new_last - last);
          show(av[i][0]);
          break;

        case '*':
          last = *ite;
          _storage.pop_back();
          ite = _storage.end();
          new_last = *ite;
          _storage.pop_back();
          _storage.push_back(new_last * last);
          show(av[i][0]);
          break;

        case '/':
          last = *ite;
          _storage.pop_back();
          ite = _storage.end();
          new_last = *ite;
          _storage.pop_back();
          _storage.push_back(new_last / last);
          show(av[i][0]);
          break;
      }
    }
  }
  std::cout << *_storage.end() << std::endl;
}

void RPN::show(char c) const {
  std::vector<int>::const_iterator it = _storage.cbegin(),
                                   ite = _storage.cend();

  std::cout << "DEBUG: "<< c << std::endl;
  while (it != ite) {
    std::cout << *it << std::endl;
    ++it;
  }
}