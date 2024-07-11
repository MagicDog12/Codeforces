#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll solve(ll n, int k, vector<ll> &a) {
    int maximum = -1;
    ll res = 0;
    for(int i=0; i<k; i++) {
        if(a[i] > maximum) {
            if(maximum > 0) {
                res += maximum-1;
            }
            maximum = a[i];
        } else {
            res += a[i]-1;
        }
    }
    res += n-maximum;
    return res;
}

int main(){ 
    int t;
    cin >> t;
    while(t--) {
        ll n;
        int k;
        cin >> n >> k;
        vector<ll> a(k);
        for(int i=0; i<k; i++) {
            cin >> a[i];
        }
        cout << solve(n, k, a) << endl;
    }
    return 0;
}