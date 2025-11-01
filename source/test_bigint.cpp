#include <iostream>
#include <chrono>

#include "bigint.h"
#include "bigrand.h"

int main() {
    auto t1 = chrono::high_resolution_clock::now();
    bigint num = random_bigrange(1, 10);
    auto t2 = chrono::high_resolution_clock::now();

    chrono::duration<double, milli> duration = t2 - t1;
    cout << duration.count() << " ms" << endl;

    cout << num.bit_length() << endl;

    bigint sum = 0;
    for(int i = 0; i < 100000; i++){
        sum += random_bigrange(0, 99999);
    }

    cout << sum/(double)100000 << endl;

    return 0;
}