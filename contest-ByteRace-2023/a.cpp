#include<bits/stdc++.h>
using namespace std;

int solve(int n, vector<int> &lista) {
    int ans = 0;
    int pair = -1;
    for(int i=0; i<n; i++) {
        if (lista[i]%2==0) {
            if(pair == 1) {
                ans++;
            }
            pair = 1;
        } else {
            if(pair == 0) {
                ans++;
            }
            pair = 0;
        }
    }
    return ans;
}

int main(){ 
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> elements(n);
        for(int i=0; i<n; i++) {
            cin >> elements[i];
        }
        cout << solve(n, elements) << endl;
    }
    return 0;
}