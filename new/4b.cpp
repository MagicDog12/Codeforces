#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9+7;

ll power(ll a, ll b, ll mod = MOD) {
    a = a%mod;
    ll ans = 1;
    while(b) {
        if(b&1) {
            ans = (ans*a)%mod;
        }
        a = (a*a)%mod;
        b >>=1;
    }
    return ans;
}

ll solve(ll a, ll b, ll c) {
    ll ans = power(b, c, MOD-1) % MOD;
    return power(a, ans)%MOD;
}

int main(){
    int t;
    cin >> t;
    while (t--){
        ll a, b, c;
        cin >> a >> b >> c;
        cout << solve(a, b, c) << endl;
    }
    return 0;
}