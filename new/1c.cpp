#include <bits/stdc++.h>
using namespace std;

float cacular_particular(vector<float>& v, int v_init, float t) {
    float v_velocidad = t/(v.size()-v_init);
    float ans = v[v_init]/v_velocidad;
    return ans;
}

pair<bool, float> calcular_cuanto(vector<float> &p, vector<float> &r, int p_init, int r_init, float t)
{
    pair<bool, float> ans;
    float p_value = cacular_particular(p, p_init, t);
    float r_value = cacular_particular(r, r_init, t);
    if(p_value <= r_value) {
        ans.first = true;
        ans.second = p_value;
        return ans;
    } else {
        ans.first = false;
        ans.second = r_value;
        return ans;
    }
}

int main()
{
    int n;
    float t;
    cin >> n >> t;
    float res = 0;
    int p_init = 0, r_init = 0;
    vector<float> p, r;
    for (int i = 0; i < n; i++)
    {
        string key;
        float value;
        cin >> key >> value;
        if (key == "P")
            p.push_back(value);
        else
            r.push_back(value);
    }
    sort(p.begin(),p.end());
    sort(r.begin(),r.end());
    while (p.size() - p_init > 0 && r.size() - r_init > 0)
    {
        pair<bool, float> ans = calcular_cuanto(p, r, p_init, r_init, t);
        res += ans.second;
        // me conviene eliminar de p
        if (ans.first)
        {
            float eliminar = p[p_init];
            for(int i=p_init; i<p.size(); i++) {
                p[i] -= eliminar;
                if(p[i] == 0) {
                    p_init++;
                }
            }
        }
        // me conviene eliminar de r
        else
        {
            float eliminar = r[r_init];
            for(int i=r_init; i<r.size(); i++) {
                r[i] -= eliminar;
                if(r[i] == 0) {
                    r_init++;
                }
            }
        }
    }
    while (p.size() - p_init > 0)
    {
        // calculo p
        float ans = cacular_particular(p, p_init, t);
        float eliminar = p[p_init];
        res += ans;
        for(int i=p_init; i<p.size(); i++) {
            p[i] -= eliminar;
            if(p[i] == 0) {
                p_init++;
            }
        }
    }
    while (r.size() - r_init > 0)
    {
        // calculo r
        float ans = cacular_particular(r, r_init, t);
        float eliminar = r[r_init];
        res += ans;
        for(int i=r_init; i<r.size(); i++) {
            r[i] -= eliminar;
            if(r[i] == 0) {
                r_init++;
            }
        }
    }
    cout << res << endl;
    return 0;
}