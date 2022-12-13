#include <bits/stdc++.h>
using namespace std;

bool find(vector<int> vec, int k){
	int tamano = vec.size();
	int l = 0;
	int r = tamano;
	int mid;
	while(l < r){
  		mid = (l+r)/2; 
  		if(vec[mid]>=k){
  			r = mid;
  		}
  		else{
  			l = mid+1;
  		}
	}
	if(vec[l]!=k){
		return false;
	}
	else{
		return true;
	}
}

bool revisar(int n){
	if(n<2){
		return false;
	}
	vector<int> triangular_numbers(0);
	int i = 1;
	int x;
	while(true){
		x = i * (i+1)/2;
		if(x>=n){
			break;
		}
		triangular_numbers.push_back(x);
		i++;
	}
	for(int j=0; j<i; j++){
		int aux = n - triangular_numbers[j];
		if(find(triangular_numbers, aux)){
			return true;
		}
	}
	return false;
}

int main(){
	int n;
	cin >> n;
	if(revisar(n)){
		cout << "YES" << endl;
	}
	else{
		cout << "NO" << endl;
	}
	return 0;
}