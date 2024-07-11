#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Función para calcular el GCD usando el algoritmo de Euclides
ll gcd(ll a, ll b) {
    while (b) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

ll solve(ll n, ll m) {
    ll count = 0;
    for(ll b=1; b<=m; b++) {
        for(ll a=b; a<=n; a+=b) {
            count += ((a+b)%(b*gcd(a,b))==0);
        }
    }
    return count;
}

int main(){
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        cout << solve(n, m) << endl;

    }
    return 0;
}