#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(int n, int m, int k) {
    vector<int> permutation(n);

    for (int i=0; i<n-m; ++i) {
        permutation[i] = n-i;
    }

    for (int i=n-m; i<n; ++i) {
        permutation[i] = i-(n-m)+1;
    }

    for (int i=0; i<n; ++i) {
        cout << permutation[i] << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        solve(n, m, k);
    }
    return 0;
}
