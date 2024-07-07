#include <bits/stdc++.h>
using namespace std;

long long solve(long long n) {
    long long res = n*floor((n-1)/2);
    if (n%3==0) {
        return res-2*n/3;
    } else {
        return res;
    }
}

int main()
{
    long long n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}