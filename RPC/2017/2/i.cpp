#include <bits/stdc++.h>
using namespace std;
/**              Posicion         NumCartas   **/
#define li pair<long long int, long long int>
long long int dos = 2;

long long int distancia(priority_queue<li> &valores, long long int k)
{
    li i = valores.top();
    valores.pop();

    long long int resultado = i.second/k; //Cuantas veces
    long long int faltantes = i.second%k; // faltantes
    long long int donde = i.first;

//    cout << k << " ";

    if(faltantes==0)
    {
        k = 0;
    }
    else
    {

        resultado+=1;
        k-=faltantes;

//        cout << k << endl;

        while(k>0 && !valores.empty())
        {
            li actual = valores.top();
            valores.pop();
            if(k >= actual.second)
            {
                k-=actual.second;
            }
            else
            {
                valores.push(li(actual.first, actual.second-k));
                k=0;
            }
        }
    }

    return donde*resultado*dos;
}

int main()
{
    int n;
    long long int x, m, k;
    priority_queue<li> pos, neg;
    cin >> n >> k;
//    scanf("%d %d", &n, &k);
//    cout << n << " " << k << endl;
    for(int i = 0; i<n; ++i)
    {
        cin >> x >> m;
//        scanf("%lld %lld", &x, &m);
//        cout << x << " " << m << endl;

        if(x>0)
        {
            pos.push(li(x,m));
        }
        else if(x<0)
        {
            neg.push(li(-x,m));
        }
    }

    long long int respuesta = 0;
    while(pos.size()>0)
    {
        respuesta+=distancia(pos,k);
    }
    while(neg.size()>0)
    {
        respuesta+=distancia(neg,k);
    }
    cout << respuesta << endl;
    return 0;
}
