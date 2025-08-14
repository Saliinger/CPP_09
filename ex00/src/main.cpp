#include "../include/Exchange.hpp"

int main(int ac, char **av) {
    (void)ac;
    (void)av;
    Exchange bitecoin(DATA_PATH);
    bitecoin.show();
    return 0;
}