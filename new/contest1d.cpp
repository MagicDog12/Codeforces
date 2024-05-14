#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> S;
    vector<vector<char>> T;
    S.resize(m, vector<char>(n));
    T.resize(m, vector<char>(n));
    vector<bool> visitados(n);
    for (int i=0; i<n; i++) {
        for(int j=0; j<m; j++) cin >> S[j][i];
    }
    for (int i=0; i<n; i++) {
        for(int j=0; j<m; j++) cin >> T[j][i];
    }
    sort(S.begin(),S.end());
    sort(T.begin(),T.end());
    for(int j=0; j<m; j++) {
        for(int i=0; i<n; i++) {
            if(S[j][i] != T[j][i]) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}