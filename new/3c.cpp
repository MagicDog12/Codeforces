#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

class Ufset {
public:
    // Constructor
    Ufset(int n);

    // Método para consultar por un set
    int findp(int i);
    // Método para unir dos sets
    void uni(int i, int j);
    // Método para 
    bool equalFind(int i, int j);

private:
    vector<int> p,s;
    int n;
    int edgesCount; 
    vector<pair<int, int>> edges;
};

// Implementación del constructor
Ufset::Ufset(int valorInicial) : n(valorInicial) {
    p.resize(n);
    for (int i=0;i<n;i++) p[i] = i;
    s.assign(n,1);
    edgesCount = 0;
}

int Ufset::findp(int i){
    return (p[i] == i)?i:p[i] = findp(p[i]);
}

void Ufset::uni(int i,int j){
    int pi = findp(i), pj = findp(j);
    if (pi != pj){
        if (s[pi] >= s[pj]){
            p[pj] = pi;
            s[pi] += s[pj];
        } else {
            p[pi] = pj;
            s[pj] += s[pi];
        }
    }
}

bool Ufset::equalFind(int i, int j) {
    return findp(i) != findp(j);
}

int main() {
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    Ufset sapo(n+1);
    Ufset sepo(n+1);
    for(int i=0; i<m1; i++) {
        int u, v;
        cin >> u >> v;
        sapo.uni(u, v);
    }
    for(int i=0; i<m2; i++) {
        int u, v;
        cin >> u >> v;
        sepo.uni(u, v);
    }
    vector<ii> edges;
    for(int i=1; i<=n; i++) {
        for(int j=i+1; j<=n; j++) {
            if(sapo.equalFind(i, j) && sepo.equalFind(i, j)){
            sapo.uni(i, j);
            sepo.uni(i, j);
            edges.push_back({i, j});
            }
        }
    }
    cout << edges.size() << endl;
    if (edges.size()) {
        for(auto edge: edges) {
            cout << edge.first << " " << edge.second << endl;
        }
    }
    
    return 0;
}