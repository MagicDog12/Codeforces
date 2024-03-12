#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> recuento(n, 0);
    int cambios = 0;
    for(int i=0; i < n; i++) {
        int a;
        cin >> a;
        if(a > n) cambios++;
        else recuento[a-1]++;
    }
    for(int j=0; j < n; j++) {
        cambios += max(0,recuento[j]-1);
    }

    cout << cambios << endl;

    return 0;
}