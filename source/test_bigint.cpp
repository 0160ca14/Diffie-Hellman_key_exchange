#include "bigint.h"

int main() {
    bigint x = bigint("120");
    bigint y = bigint("5");
    cout << x / y << endl;

    mt19937 rng(1);

    for (int i = 0; i < 1000; i++) {
        int n = uniform_int_distribution<int>(1, 100)(rng);
        bigint a = random_bigint(n);
        bigint res = sqrt(a);
        bigint xx = res * res;
        bigint yy = (res + 1) * (res + 1);

        if (xx > a || yy <= a) {
            cout << i << endl;
            cout << a << " " << res << endl;
            break;
        }

        int m = uniform_int_distribution<int>(1, n)(rng);
        bigint b = random_bigint(m) + 1;
        res = a / b;
        xx = res * b;
        yy = b * (res + 1);

        if (xx > a || yy <= a) {
            cout << i << endl;
            cout << a << " " << b << " " << res << endl;
            break;
        }
    }

    {
        bigint a = random_bigint(10'000);
        bigint b = random_bigint(2000);
        auto t1 = chrono::high_resolution_clock::now();
        bigint c = a / b;
        auto t2 = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> duration = t2 - t1;
        cout << duration.count() << " ms" << endl;
        cout << endl;
    }

    bigint a = random_bigint(200'000);
    bigint b = random_bigint(200'000);
    bigint c1, c2;
    {
        auto t1 = chrono::high_resolution_clock::now();
        c1 = a * b;
        auto t2 = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> duration = t2 - t1;
        cout << duration.count() << " ms" << endl;
    }
    {
        auto t1 = chrono::high_resolution_clock::now();
        c2 = a.mul_simple(b);
        auto t2 = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> duration = t2 - t1;
        cout << duration.count() << " ms" << endl;
    }
    cout << (c1 == c2) << endl;

    return 0;
}