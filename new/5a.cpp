#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9+7;
 
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
 
ll solve(ll l, ll r, ll k){
    if(k >= 10){
        return 0;
    } else {
        if(10%k == 0) {
            return (power(10/k,r)-power(10/k,l)+MOD)%MOD;
        } else {
            return (power(10/k+1,r)-power(10/k+1,l)+MOD)%MOD;
        }
    }  
}
 
int main(){
    int t;
    cin >> t;
    while(t--) {
        ll l, r, k;
        cin >> l >> r >> k;
        cout << solve(l, r, k) << endl;
    }
    return 0;
}