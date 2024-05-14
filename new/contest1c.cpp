#include <bits/stdc++.h>
using namespace std;

vector<vector<long long>> adj;
long long cNodos, cAristas;
vector<bool> visitados(cNodos+1, false);

long long respuesta = 0;

pair<long long, long long> bfs(long long nodo)
{
    queue<long long> q;
    q.push(nodo);
    visitados[nodo] = true;
    long long cantidadNodos = 1;
    long long cantidadAristas = 0;
    cantidadAristas += adj[nodo].size();


    while (!q.empty())
    {
        long long n = q.front();
        q.pop();

        for (long long vecino : adj[n])
        {

            if (!visitados[vecino])
            {
                q.push(vecino);
                visitados[vecino] = true;
                cantidadNodos += 1;
                cantidadAristas += adj[vecino].size();
            }
        }
    }
    return {cantidadNodos, cantidadAristas / 2};
}

int main()
{

    cin >> cNodos >> cAristas;
    adj.resize(cNodos+1);
    visitados.resize(cNodos+1, false);
    for (long long i = 0; i < cAristas; i++)
    {
        long long a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (long long i = 1; i < cNodos + 1; i++)
    {
        if (!visitados[i])
        {
            pair<long long, long long> cantidades = bfs(i);
            respuesta += (cantidades.first - 1) * cantidades.first / 2 - cantidades.second;
        }
    }
    cout << respuesta << endl;
}