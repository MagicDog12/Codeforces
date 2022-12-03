#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Creacion del SegmentTree
struct SegmentTree{
    int N;
    vector <ll> tree;
    ll neutro = 0;
    int piso;

    SegmentTree(vector <ll> &A, int n){ // pasar por referencia
        N = A.size();
        tree.resize(4*N);
        piso = n;
        build(0, 0, N-1, A, piso);
    }

    ll mergeOR(ll a, ll b){
        return a|b;
    }

    ll mergeXOR(ll a, ll b){
        return a^b;
    }

    void build(int n, int i, int j, vector <ll> &A, int piso){
        // n: la id del nodo actual
        // i, j: el intervalo que estamos mirando
        // A: el vector de inicializacion
        if(i==j){
            tree[n] = A[i];
            return;
        }
        int mid = (i+j)/2;
        build(2*n+1, i, mid, A, piso-1);
        build(2*n+2, mid+1, j, A, piso-1);
        if(piso%2==0){ // piso es par usamos XOR
            tree[n] = mergeXOR(tree[2*n+1], tree[2*n+2]);
        }
        else{ // piso es impar usamos OR
            tree[n] = mergeOR(tree[2*n+1], tree[2*n+2]);
        }
    }

    void update(int t, ll val){
        // actualizamos el indice t con valor nuevo val
        update(0, 0, N-1, t, val, piso);
    }

    void  update(int n, int i, int j, int t, ll val, int piso){
        if(t < i || t > j){
            return;
        }
        if(i == j){
            tree[n] = val;
            return;
        }
        int mid = (i+j)/2;
        update(2*n+1, i, mid, t, val, piso-1);
        update(2*n+2, mid+1, j, t, val, piso-1);
        if(piso%2==0){ // piso es par usamos XOR
            tree[n] = mergeXOR(tree[2*n+1], tree[2*n+2]);
        }
        else{ // piso es impar usamos OR
            tree[n] = mergeOR(tree[2*n+1], tree[2*n+2]);
        }
    }

    ll top(){
        return tree[0];
    }
};

int main(){
    // LECTURA DEL INPUT
    int n; // tamaño del arreglo de 2^n
    cin >> n;
    int m; // Cantidad de consultas
    cin >> m;
    int tamano = pow(2, n);
    vector <ll> arreglo(tamano);
    for(int i=0; i<tamano; i++){
        cin >> arreglo[i];
    }

    // Creamos el SegmentTree con la información
    SegmentTree ST(arreglo,  n);
    int i;
    ll x;
    while(m>0){
        cin >> i;
        cin >> x;
        ST.update(i-1,x);
        cout << ST.top() << endl;
        m--;
    }
    return 0;
}