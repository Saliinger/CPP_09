#include "../include/Exchange.hpp"

int main(int ac, char **av) {
  if (ac == 2) {
    (void)av;
    Exchange bitecoin(DATA_PATH);
    bitecoin.show();
    // new method to find closest prices and display in real time
  }
  return 0;
}