#include <bits/stdc++.h>
using namespace std;

int main(){
    // LECTURA DEL INPUT
    int t;
    cin >> t;
    while(t>0){
        int a, b, p;
        cin >> a;
        cin >> b; 
        cin >> p;
        string camino;
        cin >> camino;
        int n = camino.size();
        vector <long long> valores(n);
        valores[n-1] = 0;
        char antes = ' ';
        if(n==1){
            cout << 1 << endl;
            return 0;
        }
        for(int i=n-2; i>=0; i--){
            if(i==n-2){ // Caso Base
                if('A'==camino[i]){
                    valores[i] = a;
                    antes = 'A';
                }
                else{
                    valores[i] = b;
                    antes = 'B';
                }
            }
            else{
                if('A'==camino[i]){
                    if(antes == 'A'){
                        valores[i] = valores[i+1];
                    }
                    else{
                        valores[i] = valores[i+1]+a;
                        antes = 'A';
                    }
                }
                else{
                    if(antes=='B'){
                        valores[i] = valores[i+1];
                    }
                    else{
                        valores[i] = valores[i+1]+b;
                        antes = 'B';
                    }
                }
            }
        }
        
        // Busqueda binaria
        int l, r, mid;
        l = 0;
        r = n-1;
        while(l<r){
            mid = (l+r)/2;
            if(valores[mid]<=p){
                r = mid;
            }
            else{
                l = mid+1;
            }
        }
        // Analisis de la respuesta
        if(valores[l]>p){ // condición es falsa en l
            cout << n << endl;
        }
        else{
            cout << l+1 << endl;
        }
        t--;
    }
    return 0;
}