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

int solve(int n, int a, int i, int g) {
    ll applicants = power((Fact[i]* mod_inv(Fact[g]*Fact[i-g])) % MOD, a);
    ll groups = (Fact[n]* mod_inv(Fact[a]*Fact[n-a])) % MOD;
    return groups*applicants %MOD;
}

int main(){
    calculate_facts();
    int n, a, i, g;
    while(cin >> n >> a >> i >> g) {
        cout << solve(n, a, i, g) << endl;
    }
    return 0;
}