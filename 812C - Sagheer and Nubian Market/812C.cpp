    #include <iostream> 
    using namespace std ;
    #include <vector> 
    #include <algorithm>
     
    int main(){
    	// Input
    	long long n, S ;
    	cin >> n >> S ;
    	vector<long long> a(n);
    	for(long long i=0 ; i<n ; i++){
    		cin >> a[i] ;
    	}
    	// Busqueda Binaria
    	long long A = 0 ;
    	long long B = n ;
    	long long respuesta1=0 ;
    	long long respuesta2=0 ;
    	while(A<B){
    		long long k ;
    		k = A + (B-A)/2 ;
    		if(B-A==1){
    			k ++ ;
    		}
    		// Para cada k debemos crear un arreglo costo
    		vector<long long> costo(n) ;
    		for(long long i=0 ; i<n ; i++){
    			costo[i] = a[i] + (i+1)*k ;
      		}
      		long long T=0 ;
                // Ordenamos el arreglo
       		sort(costo.begin(),costo.end()) ;
    		for(long long i=0 ; i<k ; i++){
    			T = T + costo[i] ;
    		}
      		// Preguntamos si es valida con este k
      		if(T>S){
      			B = k-1 ;
      		}
      		else{
      			A = k ;
      			respuesta1 = k ;
      			respuesta2 = T ;
      		}
    	}
    	cout << respuesta1 << " " << respuesta2 ;
    	return 0 ;
    }