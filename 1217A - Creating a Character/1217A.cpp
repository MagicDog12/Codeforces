#include <iostream>
using namespace std;

int main(){
  int T;
  cin >> T;
  while(T>0){
    long long fuerza, inteligencia, experiencia ;
    cin >> fuerza >> inteligencia >> experiencia ;
    // Busqueda binaria
    long long A, B ;
    A = inteligencia ;
    B = inteligencia + experiencia ;
    while (A < B){
      long long mid = A + (B-A)/2 ;
      long long fuerza_nueva= fuerza + (experiencia-(mid-inteligencia)) ;
      if(mid < fuerza_nueva)
        A = mid + 1;
      else
        B = mid ;
    }
    // Caso especial
    if(fuerza-inteligencia>experiencia)
      A++ ;
    long long respuesta = A-inteligencia ;
    cout << respuesta << "\n" ;
    T-- ;
  }

  return 0;
}