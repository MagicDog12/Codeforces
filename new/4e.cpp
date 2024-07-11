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

string solve(ll n, ll c, ll g) {
    int ans = (c/gcd(c, g) <= n) && (g/gcd(c, g) <= n);
    return ans ? "SI" : "NO";
}

int main(){
    ll n, c, g;
    cin >> n >> c >> g;
    cout << solve(n, c, g) << endl;
    return 0;
}