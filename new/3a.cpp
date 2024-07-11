#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
const ll INF = 1e16;

class Dijkstra {
public:
    // Constructor
    Dijkstra(int n);

    // Método para añadir una nueva arista
    void addEdge(int u, int v, int w);
    // Método para correr el algoritmo
    void run(int s);
    // Método para revisar si hay caminos entre el nodo 1 y el nodo n
    bool isValid();
    // Método para encontrar el camino más corto entre el nodo 1 y el nodo n
    vector<int> path();

private:
    int nodos;
    vector<vector<ii>> gr;
    vector<ll> distancia;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    vector<int> parent;
};

// Implementación del constructor
Dijkstra::Dijkstra(int valorInicial) : nodos(valorInicial) {
    gr.resize(nodos+1);
    distancia.resize(nodos+1, INF);
    parent.resize(nodos+1, -1);
}

// Método para añadir una nueva arista
void Dijkstra::addEdge(int u, int v, int w) {
    gr[u].push_back({v, w});
    gr[v].push_back({u, w});
}
// Método para correr el algoritmo
void Dijkstra::run(int s) {
    pq.push({0, s});
    distancia[s] = 0;
    while (!pq.empty()) {
        // Sacamos el nodo que esté a menor distancia ahora mismo
        auto [nodo_d, nodo] = pq.top();
        pq.pop();

        // Si su distancia es mayor que la distancia que tenemos guardada
        // significa que esta distancia ya se actualizó y no nos sirve
        if (nodo_d > distancia[nodo])
            continue;
        
        // Revisamos sus vecinos
        for (auto [vecino, peso]: gr[nodo]) {
            // Si no lo hemos visitado o su distancia es menor que la podemos conseguir ahora lo cambiamos
            if (distancia[vecino] == -1 || distancia[nodo] + peso < distancia[vecino]) {
                distancia[vecino] = distancia[nodo] + peso;
                parent[vecino] = nodo;
                pq.push({distancia[vecino], vecino});
            }
        }
    }
}

bool Dijkstra::isValid() {
    if (distancia[nodos] == INF) {
        return false;
    } else {
        return true;
    }
}

vector<int> Dijkstra::path() {
    vector<int> path;
    for (int v = nodos; v != -1; v = parent[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    int n, m;
    cin >> n >> m;
    Dijkstra grafo(n);
    for(int i=0; i<m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        grafo.addEdge(u, v, w);
    }
    grafo.run(1);
    if (!grafo.isValid()) {
        cout << -1 << endl;
    } else {
        for (int v : grafo.path()) {
            cout << v << " ";
        }
        cout << endl;
    }
    return 0;
}