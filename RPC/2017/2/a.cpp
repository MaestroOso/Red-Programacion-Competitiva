#include <bits/stdc++.h>
using namespace std;
int lis[51]={0};

int cuantos(string palabra, int i)
{
    lis[0] = 1;
    for(int i = 1; i<palabra.size(); ++i){
        int maxi = 1;
        for(int j = 0; j<i; ++j){
            if(palabra[j] < palabra[i])
                maxi = max(maxi, lis[j] + 1);
        }
        lis[i] = maxi;
    }
    int maxi = 0;
    for(int i = 0; i<palabra.size(); ++i){
        maxi = max(maxi,lis[i]);
    }
    return maxi;
}

int main()
{
    string palabra;
    cin>>palabra;
    cout<<26-cuantos(palabra,0)<<endl;
    return 0;
}
