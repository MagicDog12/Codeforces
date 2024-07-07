#include <iostream>
using namespace std;

int main(){
 int largo,ancho,largoB,anchoB;
 cin >> largo >> ancho;
 cin >> largoB >> anchoB;
 int nf = largo/largoB;
 if(largo%largoB != 0)nf+=1;
 int nc = ancho/anchoB;
 if(ancho%anchoB != 0)nc+=1;
 cout << nf*nc;
}