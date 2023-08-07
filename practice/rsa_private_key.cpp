#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll extendedEuclid(ll a, ll b, ll& x, ll& y){
    if( b == 0){
        x = 1;
        y = 0;
        return a;
    }

    ll x1, y1;
    ll gcd = extendedEuclid(b, a%b, x1, y1);

    x = y1;
    y = x1 - (a/b)*y1;

    return gcd;
}

ll modInvers(ll e, ll phi_n){
    ll x, y;

    ll gcd = extendedEuclid(e, phi_n, x, y);

    if(gcd != 1){
        cerr<<"Inverse doesn't exist!!"<<endl;
        exit(1);
    }

    x = (x % phi_n + phi_n) % phi_n;
    return x;
}


int main(){
    ll n = 670726081;
    ll e = 12345713;

    ll p, q, phi_n;
    for(int i = 3; i*i <= n; i+=2){
        if( n % i == 0){
            p = i;
            break;
        }
    }
    q = n /p;

    phi_n = (p-1) * (q-1);

    ll d = modInvers(e, phi_n);

    cout << "Private Key (d): " << d << endl;
    cout << "Correctness : " << ((d % phi_n) * (e % phi_n)) % phi_n<< endl;

    return 0;
}