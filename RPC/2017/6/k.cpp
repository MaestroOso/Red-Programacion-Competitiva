#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        char letra;
        double d, aTotal = 0;
        double l1=0, l2=0;
        bool c1 = false, c2 = false, c3 = false;
        while(n--)
        {
            cin >> letra >> d;

            if(letra== 'C' || letra == 'S')
            {
                aTotal += (d*d);
            }
            else
            {
                aTotal += (d*d*sqrt(3))/4;
            }

            if(letra=='C')
            {
                if(!c1)
                {
                    c1 = true;
                }
                else if(!c2)
                {
                    c2 = true;
                    l1+=d;
                }
                else if(!c3)
                {
                    c3 = true;
                    l2+=d;
                }
            }

            if(c1 && !c2){
                l1+= d;
            }
            if(c2 && !c3){
                l2+=d;
            }

        }
        //cout << l1 << " " << l2 << endl;
        double res = (l1*l2) - aTotal;
        printf("%.4f\n", res);
    }
    return 0;
}
