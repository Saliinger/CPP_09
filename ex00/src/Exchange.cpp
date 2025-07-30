#include "../include/Exchange.hpp"

// orthodox cannonical form
Exchange::Exchange() {}

Exchange::Exchange(const Exchange &src) {
    _records = src._records;
    _exchange_rate = src._exchange_rate;
}

Exchange &Exchange::operator=(const Exchange &src) {
    if (this != &src) {
        _records = src._records;
        _exchange_rate = src._exchange_rate;
    }
    return *this
}

Exchange::Exchange() {}

// function
