#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 998244353;
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

ll solve(int n, int k) {
    if (n == 2){
        return 0;
    } else {
        ll ans = (Fact[n-1] * Fact[k-n+1])%MOD;
        ans = (mod_inv(ans)*Fact[k])%MOD;
        ans = (ans * (n-2))%MOD;
        ans = (ans * power(2, n-3))%MOD;
        return ans;
    }
}

int main(){ 
    calculate_facts();
    int n, k;
    cin >> n >> k;
    cout << solve(n, k) << endl;
    return 0;
}