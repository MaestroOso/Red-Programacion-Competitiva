#include <bits/stdc++.h>
using namespace std;
int main()
{


        string pepe;
        vector<int> letras(26,0);
        cin>>pepe;
        int comp = 0;
        for(int i =0; i< pepe.size(); ++i)
        {
            if(letras[pepe[i]-'a']==0)
            {
                comp++;
            }
            letras[pepe[i]-'a']++;
        }
        sort(letras.begin(), letras.end());
        if(comp<=2){
            cout<<0<<endl;
        }else{
        int cont = 0,suma=0;
        for(int i = 0; i<letras.size(); i++)
        {
            if(letras[i]==0)
            {
                continue;
            }
            else
            {
                suma+=letras[i];
                cont++;

                if(cont>=comp-2)
                    break;
            }
        }
        cout<<suma<<endl;
    }

    return 0;
}
