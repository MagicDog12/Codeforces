#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    long long x;
    cin >> n;
    cin >> x;
    vector<pair<long long, int>> v(n);
    for(int i=0; i<n; i++) {
        cin >> v[i].first;
        v[i].second = i+1;
    }
    sort(v.begin(), v.end());
    for(int i=0; i < n-3; i++) {
        for(int j=i+1; j<n-2; j++) {
            int left = j+1;
            int right = n-1;
            while (left < right) {
                long long sum = v[i].first + v[j].first + v[left].first + v[right].first;
                if (sum == x) {
                    cout << v[i].second << " " << v[j].second << " " << v[left].second << " " << v[right].second << endl;
                    return 0;
                } else if (sum < x) {
                    left++;
                } else {
                    right--;
                }
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}