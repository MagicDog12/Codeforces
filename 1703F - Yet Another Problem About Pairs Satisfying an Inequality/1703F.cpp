#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t>0){
        // Lectura del input
        int n;  // Largo del vector a
        cin >> n;
        vector <long long> a(n);
        for(int i=0; i<n; i++){
            cin >> a[i];
        }

        vector <long long> b;
        long long respuesta = 0;

        for(int j=0; j<n; j++){
            if(a[j]<j+1){
                // Busqueda binaria sobre el vector b
                int l, r, mid;
                long long consulta_actual = a[j];
                l = 0;
                r = b.size()-1;
                while(l<r){
                    mid = (l+r)/2;
                    if(b[mid]>=consulta_actual){
                        r = mid;
                    }
                    else{
                        l = mid+1;
                    }
                }
                // Aumento el numero de indices a la respuesta final
                if(b.size()!=0){
                    respuesta+=l;
                    if(b[l]<consulta_actual){
                        respuesta++;
                    }
                }
                // Agrego el j al vector b
                b.push_back(j+1);
            }
        }
        cout << respuesta << endl;
        t--;
    }
    return 0;
}