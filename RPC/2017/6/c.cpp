#include <bits/stdc++.h>
using namespace std;

struct puntos{
    int xp, atk, def;

    puntos(){
        xp = atk = def = 0;
    }

    puntos(int _xp, int _atk, int _def){
        xp = _xp; atk = _atk; def = _def;
    }

    bool operator == (puntos other) const
    {
        return (xp==other.xp && atk==other.atk && def==other.atk);
    }

    bool operator < (puntos other) const
    {
        if(xp == other.xp){
            if(atk==other.atk){
                return def < other.def;
            } else{
                return atk < other.atk;
            }
        } else{
            return xp < other.xp;
        }
    }

    void toString(){
        cout << xp << " " << atk << " " << def << endl;
    }
};

void todasC(vector<puntos> &izq, vector<puntos> &cIzq, int i, puntos res){
    //Fin Recursion
    if(i == izq.size()){
        cIzq.push_back(res);
        return;
    }

    //No Tomar Valor
    todasC(izq,cIzq,i+1,res);

    //Tomar el Valor
    res = puntos(res.xp+izq[i].xp, res.atk+izq[i].atk, res.def+izq[i].def);
    todasC(izq,cIzq,i+1,res);

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    int x, a, d, m;
    string aux;
    cin >> t;
    while(t--){
        cin >> x >> a >> d >> m;
        puntos res(x,a,d);

        vector<puntos> izq(m/2), der(m - (m/2));
        vector<puntos> cIzq, cDer;
        for(int p = 0; p< izq.size(); p++)
        {
            cin >> aux >> x >> a >> d;
            izq[p] = puntos(x,a,d);
        }
        for(int p = 0; p< der.size(); p++)
        {
            cin >> aux >> x >> a >> d;
            der[p] = puntos(x,a,d);
        }

        puntos aux(0,0,0), aux2(0,0,0);
        todasC(izq,cIzq,0,aux);
        todasC(der,cDer,0,aux2);
        sort(cIzq.begin(),cIzq.end());
        sort(cDer.begin(),cDer.end());

//        cout << cIzq.size() << " " << cDer.size() << endl;

        bool resp = false;
        for(int i = 0; i<cIzq.size(); ++i){
            puntos auxiliar = puntos(res.xp - cIzq[i].xp, res.atk - cIzq[i].atk , res.def - cIzq[i].def );
//            auxiliar.toString();
            if(binary_search(cDer.begin(), cDer.end(), auxiliar)){
                resp = true;
                break;
            }
        }

        if(resp){
            cout << "POSSIBLE\n";
        } else{
            cout << "IMPOSSIBLE\n";
        }
    }
    return 0;
}
