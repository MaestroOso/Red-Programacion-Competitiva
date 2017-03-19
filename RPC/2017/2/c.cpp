#include <bits/stdc++.h>
using namespace std;

int n, k, r, p, q, camarasActuales=0, total=0;
bool camaras[200010] = {false};

int main()
{
    cin >> n >> k >> r;
    for(int i = 0; i<k; ++i)
    {
        cin >> p;
        camaras[p] = 1;
    }

    p = 1;
    q = 2;
    if(camaras[p]) camarasActuales++;
    if(camaras[q]) camarasActuales++;

    while(q != n + 1)
    {
        if(q-p+1 < r)
        {
            q = q;
        }
        else
        {
            if(camarasActuales == 1)
            {
                if(!camaras[q])
                {
                    camaras[q] = true;
                    camarasActuales++;
                    total++;
                }
                else
                {
                    camaras[q-1] = true;
                    camarasActuales++;
                    total++;
                }
            }
            else if(camarasActuales == 0)
            {
                camaras[q] = true;
                camaras[q-1] = true;
                camarasActuales = 2;
                total+=2;
            }


        }

        if (q-p+1 == r) {
            if(camaras[p])
            {
                camarasActuales--;
            }
            ++p;
        }
        ++q;
        if(camaras[q])
        {
            camarasActuales++;
        }

    }

    printf("%d\n", total);
}
