#include <bits/stdc++.h>
using namespace std;

int calculate(int a, int b) {
 // valor inicial, a^0=1
    int ans = 1;
    int actual = a;
 // vamos revisando b digito por digito
    while (b > 0) {
 // si el dígito actual es 1, debemos multiplicar la respuesta por a^2^n
        if (b % 2 == 1)
        ans = (ans%10 * actual%10) % 10;
 // calculamos c = a^2^(n+1) como a^2^n * a^2^n
        actual = (actual%10 * actual%10) % 10;
 // le quitamos el ultimo digito a b
        b /= 2;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result = result * calculate(i, i);
        while (result % 10 == 0) {
            result = result/10;
        }
        result = result%10;
    }
    cout << result << endl;
    
    return 0;
}