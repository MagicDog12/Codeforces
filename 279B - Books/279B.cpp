#include <iostream>
using namespace std;

int main(){
	// n libros t tiempo
	int n, t;
	cin >> n >> t;
	int a[n];
	for (int i=0; i<n; i++){
		cin >> a[i];
		}

    int sum = 0;
    int cont = 0;
    int j = 0;
    for (int i= 0; i<n; i++){
        sum += a[i];
        if (sum <= t){
            cont++;
        }
        else {
            sum = sum - a[j];
            j++;
        }
    }
    cout << cont << endl;

return 0;
}
