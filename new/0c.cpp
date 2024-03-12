#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long> a(n);
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    vector<pair<long long,long long>> st(n-1);
    for(int i=0; i<n-1; i++) {
        cin >> st[i].first >> st[i].second;
    }

    for(int i=0; i<n-1; i++) {
        long long value = a[i]/st[i].first;
        a[i+1]+=value*st[i].second;
    }


    cout << a[n-1] << endl;
    return 0;
}