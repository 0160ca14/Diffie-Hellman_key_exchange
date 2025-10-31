#include <iostream>
#include <chrono>

#include "bigint.h"

int main() {
    bigint x = bigint("120");
    bigint y = bigint("5");
    cout << x / y << endl;

    cout << random_bigint(2048) << endl;

    return 0;
}