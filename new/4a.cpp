#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9+7;
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

int solve(int a, int b) {
    if (b>a) {
        return 0;
    }
    else {
        ll ans = (Fact[b] * Fact[a-b])%MOD;
        ans = (mod_inv(ans)*Fact[a])%MOD;    
        return ans;
    } 
}

int main(){
    calculate_facts();
    int t;
    cin >> t;
    while (t--){
        int a, b;
        cin >> a >> b;
        cout << solve(a, b) << endl;
    }
    return 0;
}