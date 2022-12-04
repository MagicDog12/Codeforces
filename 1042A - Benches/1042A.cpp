#include <iostream>
using namespace std;
#include <vector>

int main(){
  int n;  // [1,100]
  int m;  // [1,10000]
  cin >> n ;
  cin >> m ;
  vector<int> arreglo(n);
  for(int i=0 ; i<n ; i++){
    cin >> arreglo[i] ;
  }
  // Ordenamos el arreglo ya que maximo es de largo n
  for(int i=0 ; i<n ; i++){
    for(int j=i ; j<n ; j++){
      int aux = arreglo[i];
      if(aux>arreglo[j]){
        aux = arreglo[j] ;
        arreglo[j]=arreglo[i];
        arreglo[i]=aux ;
      }
    }
  }
  //
  vector<int> arreglo2(n) ;
  for(int i=0 ; i<n ; i++){
    arreglo2[i]=arreglo[i];
  }
  // el maximo valor de k es 
  int max_k = arreglo[n-1] + m ;
  // el menor valor de k es
  while(m>0){
    arreglo2[0]= arreglo2[0]+1 ;
    for(int k=0 ; k<n-1 ; k++){
      if(arreglo2[k]>arreglo2[k+1]){
        int aux2 = arreglo2[k+1] ;
        arreglo2[k+1]=arreglo2[k] ;
        arreglo2[k]=aux2;
      }
    }
    m-- ;
  }
  int min_k = arreglo2[n-1] ;
  cout << min_k << " " << max_k ;
  cout << "\n" ;
  return 0;
}