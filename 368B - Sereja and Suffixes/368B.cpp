#include <bits/stdc++.h>
using namespace std;

template<class T>
std::vector<int> prefixFunction(T &s){
    int n = s.size();
    std::vector<int> pi(n);
    for (int i = 1; i < n; i ++){
        int k = pi[i - 1];
        while(k > 0 and s[i] != s[k]) k = pi[k - 1];
        if (s[i] == s[k]) k ++;
        pi[i] = k;
    }
    return pi;
}

int main() {
    int n; //largo arreglo
    int m; //consultas
    cin >> n >> m;
    vector<int> a(n);//arreglo A
    vector<int> respuestas(n);//respuestas
    set<int> result;
    for (int i = 0; i < n; ++i)
    {
        int actual;
        cin >> actual;
        a[i] = actual;
        //result.insert(actual);
    }
    //cout << "calculando respuestas"<<endl;
    for (int i = n-1; i >=0; --i)
    {
        //cout<<"a[i] " << a[i] <<", result size ";
        result.insert(a[i]);
        //cout<< result.size()<<endl;
        respuestas[i] = result.size();

    }

    for (int i = 0; i < m; ++i)
    {
        int li;
        cin >> li;
        cout << respuestas[li-1]<<endl;

    }
    return 0;
}