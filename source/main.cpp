#include <iostream>

#include "bigint.h"

using namespace std;

bigint modular_exponentiation(bigint base, bigint exponent, bigint mod){
    bigint result = 1;
    base = base % mod;

    while(exponent > 0){
        if(exponent % 2 == 1){
            result = (result*base) % mod;
        }

        base = (base*base) % mod;

        exponent = exponent/2;
    }

    return result;
}


int main(){
    bigint base = random_bigint(1024);
    bigint exponent = random_bigint(1024);
    bigint mod = random_bigint(1024);

    cout << "Base: " << base << endl;
    cout << "Exponent: " << exponent << endl;
    cout << "Mod: " << mod << endl;

    cout << modular_exponentiation(base, exponent, mod) << endl;


    return 0;
}