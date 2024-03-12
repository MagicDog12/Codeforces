#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t>0) {
        long long hc, dc, hm, dm, k, w, a;
        string resp = "NO";
        cin >> hc >> dc;
        cin >> hm >> dm;
        cin >> k >> w >> a;
        for(int i=0; i<=k; i++) {
            long long vc = ceil(1.0*hm / (dc + i*w));
            long long vm = ceil(1.0*(hc + (k-i)*a)/dm);
            if( vc <= vm ) {
                resp = "YES";
                break;
            }
        }
        cout << resp << endl;
        t--;
    }
    return 0;
}