#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n;
    cin >> k;
    vector<int> v(n);
    for(int i=0; i<n; i++) {
        cin >> v[i];
    }

    int i = 0, res = 0;
    while (i < k) {
        int one = 0, two = 0;
        for(int j = i; j < n; j+=k) {
            if(v[j] == 1) {
                one++;
            } else {
                two++;
            }
        }
        res += min(n/k-one, n/k-two);
        i++;
    }
    cout << res << endl;
    return 0;
}