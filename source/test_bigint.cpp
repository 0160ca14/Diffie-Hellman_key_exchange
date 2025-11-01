#include <iostream>
#include <chrono>

#include "bigint.h"
#include "fft.h"

int main() {
    bigint num = random_bigint(512);

    cout << num << endl;

    for(auto i: num.z){
        cout << i << endl;
    }
    
    cout << num.z.back() << endl;

    return 0;
}