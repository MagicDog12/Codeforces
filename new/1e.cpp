
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; 
    cin>>t;
    while(t--){
        int n,x;
        cin >> n;
        int ans=-1e9;
        int sum1=-1e9;
        int sum2=-1e9;
        for(int i=1; i<=n; ++i){
            cin >> x;
            ans=max(ans,sum2+x-i);
            sum2=max(sum2,sum1+x);
            sum1=max(sum1,x+i);
        }
        cout << ans << endl;
    }
    return 0;
}