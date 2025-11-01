#include <iostream>

#include "bigint.h"
#include "bigrand.h"

using namespace std;

// A: Triển khai hàm lũy thừa mô-đun
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

    // Trả về kết quả
    return result;
}



// B: Triển khai hàm sinh số nguyên tố ngẫu nhiên

// Kiểm tra Miller-Rabin (nó khó hiểu thật ;(( nên phải comment nhiều )
bool miller_rabin_test(const bigint& num, int rounds = 40){
    // Xử lý các trường hợp với số nhỏ
    if(num == 2 || num == 3 || num == 5 || num == 7) return true;
    if(num <= 20) return false;
    if(num % 6 != 1 && num % 6 != 5) return false;

    // Phân tích num - 1 thành dạng 2^s * d
    bigint d = num - 1; 
    int s = 0;
    while(d % 2 == 0){
        d /= 2;
        s++;
    }

    // Lặp lại "rounds" lần với nhiều nhân chứng ngẫu nhiên
    for(int i = 0; i < rounds; i++){
        bigint witness = random_bigrange(2, num - 2);

        // Tính x = witness^d mod num
        bigint x = modular_exponentiation(witness, d, num);

        // Nếu x = 1 hoặc x = num - 1, num có thể là số nguyên tố, còn không thì ta tiếp tục thử với nhân chứng khác.
        if(x == 1 || x == num - 1) continue;

        // Lặp s - 1 lần bình phương x, nếu không tìm thấy x = num - 1 thì num chính là hợp số.
        bool is_composite = true;
        for(int r = 1; r < s; r++){
            x = (x*x) % num;

            // Nếu x = 1, ta đã tìm được một căn bậc hai không tầm thường của 1 nên n phải là hợp số
            if(x == 1) return false;

            /* Nếu x = num - 1, điều kiện được thỏa mãn cho nhân chứng này 
            Suy ra num có thể là số nguyên tố, thoát vòng lặp và kiểm tra nhân chứng khác*/
            if(x == num - 1){
                is_composite = false;
                break;
            }
        }

        if(is_composite) return false;
    }

    return true;
}

// Hàm sinh số nguyên tố lớn n bit 
bigint generate_safe_prime(int bit_size){
    if(bit_size < 2) return bigint(0);
    if(bit_size == 2) return random_bigrange(2, 3);

    while(true){
        bigint candidate = random_bigint(bit_size);

        // Nếu candidate là số chẵn thì biến nó thành số lẻ, điều này không làm tăng bit vì 2^bit_size - 1 là số lẻ
        if(candidate % 2 == 0) candidate += 1;

        // Kiểm tra Miller-Rabin
        if(miller_rabin_test(candidate) == true) return candidate;
    }
}



// C: Triển khai hàm sinh khóa riêng ngẫu nhiên


int main(){
    bigint base = random_bigint(1024);
    bigint exponent = random_bigint(1024);
    bigint mod = random_bigint(1024);

    cout << "Base: " << base << endl;
    cout << "Exponent: " << exponent << endl;
    cout << "Mod: " << mod << endl;

    cout << "Fast Powering:" << modular_exponentiation(base, exponent, mod) << endl;

    bigint prime = generate_safe_prime(1024);

    cout << "Prime: " << prime << endl;

    return 0;
}