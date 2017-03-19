#include <bits/stdc++.h>
using namespace std;

unsigned long long int barra[15], peso[15];
int n, m;

bool dif(set<int> s)
{
    for(set<int>::iterator it = s.begin(); it != s.end(); it++)
    {
        int a = *it;
        bool r;
        for(set<int>::iterator it2 = s.begin(); it2 != s.end(); it2++)
        {
            r = true;
            int b = *it2;
            for(int i = 0; i<15; ++i)
            {
                if( ((a)&(1<<i)) && ((b)&(1<<i)) )
                {
                    r = false;
                }
            }
            if(r==true)
            {
                return true;
            }
        }
    }
    return false;
}

void todasSumas(map<unsigned long long int, set<int> > &mapa, int pos, unsigned long long int res, int mascara)
{
    if(pos == m)
    {
        mapa[res].insert(mascara);
        return;
    }

    todasSumas(mapa,pos+1, res, mascara);
    todasSumas(mapa,pos+1, res+peso[pos], mascara +(1<<pos));
}

void todasSumas()
{
    map<unsigned long long int, set<int> > mapa;
    unsigned long long int res = 0;
    todasSumas(mapa, 0, res,0);
    set<unsigned long long int> diferentes;
    for(map<unsigned long long int,set<int> >::iterator it = mapa.begin(); it!=mapa.end(); it++)
    {
        if( dif(it->second))
        {
            for(int i = 0; i<n; ++i)
                diferentes.insert(2*(it->first)+barra[i]);
        }
    }

    for(set<unsigned long long int>::iterator it = diferentes.begin(); it!=diferentes.end(); it++)
    {
        cout << *it << endl;
    }

}

int main()
{

    scanf("%d %d", &n, &m);
    for(int i = 0; i<n; ++i)
    {
        cin >> barra[i];
    }
    for(int i = 0; i<m; ++i)
    {
        cin >> peso[i];
    }
    todasSumas();
    return 0;
}
