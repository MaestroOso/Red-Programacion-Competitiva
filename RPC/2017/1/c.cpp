#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<pair<string, string > > pepe;
    for(int i =0; i<n;++i)
    {
        string nombre;
        string apellido;
        cin>>nombre>>apellido;
        pepe.push_back(make_pair(apellido,nombre));
    }
    sort(pepe.begin(), pepe.end());
    for(int i=0; i< pepe.size(); ++i)
    {
        cout<<pepe[i].second<<" "<<pepe[i].first<<endl;
    }
    return 0;
}

