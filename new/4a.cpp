#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;
const ll MAX = 1e6 + 1;
vector<ll> fact(MAX);
vector<ll> inv_fact(MAX);

// Calcular la inversa modular durante el cálculo
// iterativo del coeficiente binomial
ll mod_exp(ll x, ll y, ll p)
{
    ll res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

// Calculamos los factoriales y sus inversas una vez y los almacenamos.
void pre_calculate_facts()
{
    fact[0] = 1;
    for (int i = 1; i < MAX; i++)
    {
        fact[i] = fact[i - 1] * i;
    }
    inv_fact[MAX] = mod_exp(fact[MAX], MOD - 2, MOD);
    for (int i = MAX - 1; i >= 0; i--)
    {
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % MOD;
    }
}



int calculate(int a, int b)
{
    // Calcular coeficiente binomial de (a, b) -> a!/(b!*(a-b)!)
    if (b > a)
        return 0;
    return fact[a] * inv_factorial[b] % MOD * inv_factorial[a - b] % MOD;
}

int main()
{
    pre_calculate_facts();
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        int ans = calculate(a, b);
        cout << ans << endl;
    }
    return 0;
}