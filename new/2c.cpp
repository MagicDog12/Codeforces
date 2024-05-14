#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 7; 
vector<int> adj[MAXN]; 

int main() {
    int n;
    cin >> n;
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int leafCount = 0; 
    for (int i = 1; i <= n; i++) {
        if (adj[i].size() == 1) { 
            leafCount++;
        }
    }
    cout << (leafCount + 1) / 2 << endl;
    return 0;
}
