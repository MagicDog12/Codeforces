#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long> v(n);
    for(int i=0; i<n; i++) {
        cin >> v[i];
    }

    set<long long> my_set;
    int start = 0, end = 0, res = 0;
    while (end < n) {
        if (my_set.find(v[end]) == my_set.end()) {
            my_set.insert(v[end]);
            res = max(res, end - start + 1);
            end++;
        } else {
            my_set.erase(v[start]);
            start++;
        }
    }
    cout << res << endl;
    return 0;
}