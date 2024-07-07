#include <bits/stdc++.h>
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

ll fun(ll a, ll b, ll n){
    if(b==-1)
    return 1;
    long long x=1, y=a; 
    while (b > 0) {
        if (b%2 == 1) {
            x = (x*y) % n; // multiplying with base
        }
        y = (y*y) % n; // squaring the base
        b /= 2;
    }
    return x % n;
}
 
ll solve(int n, int k){
    ll a = Fact[k];
    ll b = (Fact[n-1]*Fact[k-n+1])%MOD;
    ll g = fun(b,MOD-2,MOD);
    ll ans = ((g*a)%MOD*(n-2))%MOD;
    ans = (ans*fun(2,n-3,MOD))%MOD;
    return ans;
}
 
int main(){
    calculate_facts();
    int n, k;
    cin >> n, k;
    cout << solve(n, k) << endl;
    return 0;
}
