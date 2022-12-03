#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_function(string s){
    int n = (int)s.length();
    vector<int> pi(n);
    for(int i = 1; i < n; i++){
        int j = pi[i-1];
        while(j > 0 && s[i]!= s[j]){
            j = pi[j-1];
        }
        if(s[i] == s[j]){
            j++;
        }
        pi[i] = j;
    }
    return pi;
}

int main(){
    // LECTURA DEL INPUT
    string entrada;
    cin >> entrada;
    int n = (int)entrada.length();
    vector<int> pi(n);
    pi = prefix_function(entrada);
    int l = pi[n-1];
    if(l == 0){
        cout << "Just a legend" << endl;
        return 0;
    }
    else{
        for(int i=0; i<n-1; i++){
            if(pi[i] == l){
                for(int j=0; j<l; j++){
                    cout << entrada[j];
                }
                cout << endl;
                return 0;
            }
        }
        int lPrima = pi[l-1];
        if(lPrima > 0){
            for(int j=0; j<lPrima; j++){
                cout << entrada[j];
            }
            cout << endl;
            return 0;
        }
        else{
            cout << "Just a legend" << endl;
        }
        return 0;
    }
    
    return 0;
}