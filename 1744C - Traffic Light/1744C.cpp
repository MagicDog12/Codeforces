#include <bits/stdc++.h>
using namespace std;


int main(){
	int t;
	cin >> t;
	while(t--){
		// Lectura del input
		int n;
		cin >> n;
		char c;
		cin >> c;
		string s;
		cin >> s;

		int respuesta = 0;
		int sum = 1;
		int primera = 0;
		bool status_primera = true;
		bool status = false;
		if(c == 'g'){
			cout << 0 << endl;
			continue;
		}
	
		for(int i=0; i<n; i++){
			if(s[i]=='g' && status_primera){
				primera += i;
				status_primera = false;
			}
			if(!status){
				if(s[i]==c){
					sum = 1;
					status = true;
				}
			}
			else{
				if(s[i]=='g'){
					respuesta = max(respuesta, sum);
					sum = 0;
					status = false;
				}
				else{
					sum++;
				}
			}
		}
		// Volvemos a revisar hasta la primera g
		if(status){
			respuesta = max(respuesta, sum+primera);
		}
		cout << respuesta << endl;
	}

	return 0;
}