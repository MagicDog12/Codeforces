#include <iostream>
using namespace std;

int main(){
	int t;
	long long x,y ;
	long long z;
	cin >> t ;
	while(t>0){
		cin >> x >> y ;
		z = x-y ;
		if(z>=2){
			cout << "YES" << "\n" ;
		}
		else{
			cout << "NO" << "\n" ;
		}
		t-- ;
	}
	return 0;
}