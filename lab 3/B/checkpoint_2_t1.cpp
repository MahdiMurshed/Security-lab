#include<bits/stdc++.h>
using namespace std;

long long extendedGCD(long long a, long long b, long long& x, long long& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    long long x1, y1;
    long long gcd = extendedGCD(b, a % b, x1, y1);

    x = y1;
    y = x1 - (a / b) * y1;

    return gcd;
}

long long modInverse(long long e, long long phi_n) {
    long long x, y;
    long long gcd = extendedGCD(e, phi_n, x, y);

    if (gcd != 1) {
        cerr << "The modular inverse does not exist!" << endl;
        exit(1);
    }

    x = (x % phi_n + phi_n) % phi_n; // Ensure positive value

    return x;
}

int main() {
    long long n = 670726081;
    long long e = 12345713;

    long long p, q, phi_n;
    for (int i = 3; i*i <= n; i += 2)
    {
        if (n % i == 0) {
            p = i;
            break;
        }
    }
    q = n / p;

    phi_n = (p-1) * (q-1);

    // Calculate the private exponent (private key) 'd'
    long long d = modInverse(e, phi_n);

    cout << "Private Key (d): " << d << endl;

    cout << "Correctness : " << ((d % phi_n) * (e % phi_n)) % phi_n<< endl;

    return 0;
}