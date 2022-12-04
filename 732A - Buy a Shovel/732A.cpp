#include <bits/stdc++.h>
using namespace std;
int main(){
	int k;
	cin >> k;
	int r;
	cin >> r;
	int m = k;
	int i =1;
	while(!(m%10==0 or m%10-r==0)){
		m+=k;
		i +=1;

	}
	cout << i << endl;
	return 0; 
}