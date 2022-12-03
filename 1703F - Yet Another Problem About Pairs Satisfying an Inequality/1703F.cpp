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
            //cout << "Impresion de b en j=" << j+1 << ", con size=" << b.size() << endl;
            //for(int k=0; k<b.size(); k++){
            //    cout << b[k] << ".";
            //}
            //cout << endl;
            if(a[j]<j+1){
                // Busqueda binaria sobre el vector b
                int l, r, mid;
                long long consulta_actual = a[j];
                l = 0;
                r = b.size()-1;
                //cout << "Empieza BB con l=" << l << ", r=" << r << ", con a[j]=" << consulta_actual << endl;
                while(l<r){
                    mid = (l+r)/2;
                    //cout << "mid=" << mid << ".-." << endl;
                    if(b[mid]>=consulta_actual){
                        r = mid;
                    }
                    else{
                        l = mid+1;
                    }
                }
                //cout << "Termina BB con l=" << l << ", r=" << r << ", con a[j]=" << consulta_actual << endl;
                // Aumento el numero de indices a la respuesta final
                if(b.size()==0){
                    //cout << "no hay vector b" << endl;
                }
                else{
                    respuesta+=l;
                    if(b[l]>=consulta_actual){
                        //cout << "si pero b[l]>=consulta_actual" << endl;
                    }
                    else{
                        //cout << "si pero b[l]<consulta_actual" << endl;
                        respuesta++;
                    }
                }
                // Agrego el j al vector b
                b.push_back(j+1);
                //cout << "respuesta parcial = " << respuesta << endl;
            }
            //cout << "--- --- ---" << endl;
        }
        //cout << "respuesta final = " << respuesta << endl;
        cout << respuesta << endl;
        t--;
    }
    return 0;
}