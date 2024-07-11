#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9+7;

pair<ll, ll> solve(int n, int k, vector<ll> values) {
    pair<ll, ll> ans = {0, 0};
    
    for(int i=0; i<k; i++) {
        ans.first= (ans.first+values[i])%MOD;
    }
    for(int i=k; i<n; i++) {
        if((i-k)%2!=0) {
            ans.first = (ans.first+values[i])%MOD;
        } else {
            ans.second = (ans.second+values[i])%MOD;
        }
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<ll> values(n);
        for (int i = 0; i < n; ++i) {
            cin >> values[i];
        }
        pair<ll, ll> ans = solve(n, k, values);
        cout << ans.first << " " << ans.second << endl;
    }
    return 0;
}
