#include <iostream>
using namespace std;

int main(){
    int t; // casos de prueba
    cin >> t;
    while(t > 0) {
        int n, m; // tamaño de la matriz
        cin >> n >> m ;
        cout << max(n, m) << endl;
        t--;
    }
    return 0;
}