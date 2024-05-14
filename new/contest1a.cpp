#include <bits/stdc++.h>
using namespace std;

int casos;

int main()
{
    cin >> casos;
    for (int i = 0; i < casos; i++)
    {
        int cuentaU = 0;
        int largo;

        cin >> largo;
        for (int i = 0; i < largo; i++)
        {
            char letra;
            cin >> letra;
            if (letra == 'U')
            {
                cuentaU += 1;
            }
        }
        if (cuentaU % 2 == 0)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
        }
    }
    return 0;
}