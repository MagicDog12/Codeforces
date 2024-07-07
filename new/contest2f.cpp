#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void gcd(ll n) {
    ll a, b, c;
    // si es par
    if(n%2==0) {
        a = n/2-1;
        b = n/2;
        c = 1;
    } else {
        if ((n-1)%4 == 0){
            c = 1; 
            a = n/2-1;
            b = n/2+1;
        }
        else{
            a = n/2 -2;
            b = n/2+2;
            c = 1;
        }
    }
    cout << a << " " << b << " " << c << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        // cout << n/2;
        gcd(n);
    }
    return 0;
}