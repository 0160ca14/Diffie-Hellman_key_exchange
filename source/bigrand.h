# pragma once

#include "bigint.h"

bigint random_bigint(const int bit_size){
    mt19937 rng(std::random_device{}());
    uniform_int_distribution<int> distribution(0, 1);

    if(bit_size <= 0) return bigint(0);
    if(bit_size == 1) return bigint(distribution(rng));

    bigint result = 1;
    for (int i = 0; i < bit_size - 1; i++) {
        result *= 2;
        result += distribution(rng);
    }

    return bigint(result);
}

bigint random_max_bits(const int bit_size){
    mt19937 rng(std::random_device{}());
    uniform_int_distribution<int> distribution(0, 1);

    if(bit_size <= 0) return bigint(0);
    if(bit_size == 1) return bigint(distribution(rng));

    bigint result = 0;
    for (int i = 0; i < bit_size; i++) {
        result *= 2;
        result += distribution(rng);
    }

    return bigint(result);
}

bigint random_bigrange(const bigint& a, const bigint& b){
    if(a == b) return a;

    mt19937 rng(std::random_device{}());
    uniform_int_distribution<int> distribution(0, 1);

    bigint range = b - a;
    int bit_length = range.bit_length();

    bigint candidate;
    do{
        candidate = random_max_bits(bit_length);
    }while(candidate > range);

    return candidate + a;
}