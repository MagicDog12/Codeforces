#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;
const ll N = 1e6+1;
vector<ll> Fact(N); 

void calculate_facts(){
    Fact[0] = 1;
    for(int i=1; i<N+1; i++) {
        Fact[i] = Fact[i-1]*i %MOD;
    }
}

ll power(ll a, ll b) {
    a = a%MOD;
    ll ans = 1;
    while(b) {
        if(b&1) {
            ans = (ans*a)%MOD;
        }
        a = (a*a)%MOD;
        b >>=1;
    }
    return ans;
}

ll mod_inv(ll a) {
    return power(a, MOD-2);
}

ll comb(ll a, ll b) {
    ll ans = (Fact[a]* mod_inv(Fact[b]*Fact[a-b])) % MOD;
    return ans;
}

ll solve(int n) {
    // Si n es par
    if(n%2==0) { 
        return (2*comb(2*n-2, n-1))/n;
    } else {
        return (2*comb(2*n-2, n-1))/n - ((2*comb(n-1, (n-1)/2))/(n+1))*((2*comb(n-1, (n-1)/2))/(n+1));
    }
}

int main(){
    calculate_facts();
    int n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}