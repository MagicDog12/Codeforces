#include<bits/stdc++.h>
using namespace std;

int solve(int a, int b, int c) {
    int ans;
    int cnt = 5;
    while(cnt--) {
        if( a < b) { // a < b
                if (a < c) { // a < b y c
                    a++;
                } else { // c < a y b
                    c++;
                }
        } else { // b < a
            if ( b < c) { // b < a y c
                b++;
            } else { // c < a y b
                c++;
            }
        }
    }
    return a*b*c;
}

int main(){ 
    int t;
    cin >> t;
    while(t--) {
        int a, b, c;
        cin >> a >> b >> c;
        cout << solve(a, b, c) << endl;
    }
    return 0;
}