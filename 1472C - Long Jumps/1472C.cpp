#include <bits/stdc++.h>
using namespace std;

int main(){
    // LECTURA DEL INPUT
    int t; // Cantidad de pasos
    cin >> t;

    while(t>0){
        int n;
        cin >> n;
        vector <int> arreglo(n);
        for(int i=0; i<n; i++){
            cin >> arreglo[i];
        }
        // FIN DE LECUTRA DEL INPUT

        vector <int> respuestas(n);
        for(int i=0; i<n; i++){
            respuestas[i] = 0;
        }
        for(int i=n-1; i>=0; i--){
            // Se acaba el juego
            if(i+arreglo[i]>=n){
                respuestas[i]+=arreglo[i];
            }
            else{
                respuestas[i]+=arreglo[i];
                respuestas[i]+=respuestas[i+arreglo[i]];
            }
        }

        sort(respuestas.begin(), respuestas.end());
        cout << respuestas[n-1] << endl;
        t--;
    }
    return 0;
}