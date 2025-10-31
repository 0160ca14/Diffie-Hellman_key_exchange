#include <iostream>
#include <chrono>

#include "bigint.h"
#include "fft.h"

int main() {
    bigint x = bigint("120");
    bigint y = bigint("5");
    cout << x / y << endl;

    cout << random_bigint(2048) << endl;

    bigint z = bigint(1);

    cout << z << endl;

    return 0;
}