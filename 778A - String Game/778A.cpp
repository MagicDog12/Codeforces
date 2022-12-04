#include <iostream> 
using namespace std ;
#include <vector> 

int main(){
	// Input :
	string t, p ;
	cin >> t >> p ;
	int modulo_de_t = t.size() ;
	vector<int> a(modulo_de_t) ;
	for(int i=0 ; i<modulo_de_t ; i++){
		cin >> a[i] ;
	}
	// Busqueda binaria :
	int A = 0;
	int B = modulo_de_t-1;
	int mitad ;
	while(A<B){
		mitad = A + (B-A)/2 ;
		// La pregunta en la mitad debe negarse ya que la busqueda binaria según este problema es de
		// la forma SI SI SI NO NO y necesitamos que sea de la forma NO NO NO SI SI
		// y si la respuesta en este caso era 2+1 (ya que 2 viene del indice de a)
		// ahora nuestra respuesta será 3 (ya que 3 viene del indice de a)
		string t_en_mitad = t ;
		int indice ;
		for(int i=0 ; i<mitad+1 ; i++){
			// vamos a ir quitando las letras de t hasta llegar a t_en_mitad
			indice = a[i] ;
			t_en_mitad.replace(indice-1, 1 ,"A") ;
			//t_en_mitad[indice-1] = "A" ; // "A" en vez de la letra que este aquí
		}
		bool pregunta_en_mitad = false ;
		int check_point = 0 ;
		int j=0 ;
		while(j<p.size()){
			if(check_point>modulo_de_t){
				// Si es que p no está en t_en_mitad
				pregunta_en_mitad = true ;
				break ;
			}
			if(p[j]==t_en_mitad[check_point]){
				check_point++ ;
				j++ ;
			}
			else{
				check_point++ ;
			}
		}
		//
		if(pregunta_en_mitad){
			B = mitad ;
		}
		else{
			A = mitad + 1;
		}
	}
	cout << A << "\n" ;
	return 0 ;
}