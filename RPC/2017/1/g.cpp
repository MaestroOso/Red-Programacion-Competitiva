#include <bits/stdc++.h>
using namespace std;
#define ii pair<int,int>

int n, m;
int INF = 10000000;

int Dijkstra(vector<vector<int> > &grafo, int origen){
    priority_queue<ii, vector<ii>, greater<ii> > cola;
    vector<int> dists(grafo.size(), INF);
    cola.push(ii(0,origen));
    dists[origen] = 0;
    while(!cola.empty()){
        ii actual = cola.top(); cola.pop();
        int o = actual.second;
        int costo = actual.first;
        if(costo<=dists[o]){
            for(int i = 0; i<grafo[o].size(); ++i){
                int d = grafo[o][i];
                int costoArista = 1;
                if(dists[o]+costoArista < dists[d]){
                    dists[d] = dists[o]+costoArista;
                    cola.push(ii(dists[d],d));
                }
            }
        }
    }
    return dists[grafo.size()-1];
}


bool posValida(int i, int j)
{
    if(i<0 || i>=m || j<0 || j>=n)
    {
        return false;
    }
    return true;
}

int posGrafo(int i, int j){
    return i*n + j;
}

int main()
{
    cin >> m >> n;
    vector<vector<int> >grafo(m*n);
    int delta;
    char c;
    for(int i = 0; i<m; ++i)
    {
        for(int j=0; j<n; ++j)
        {
            cin >> c;
            delta = c-'0';
            if(delta==0){
                continue;
            }
            if(posValida(i+delta,j)){
                grafo[posGrafo(i,j)].push_back(posGrafo(i+delta,j));
            }
            if(posValida(i-delta,j)){
                grafo[posGrafo(i,j)].push_back(posGrafo(i-delta,j));
            }
            if(posValida(i,j+delta)){
                grafo[posGrafo(i,j)].push_back(posGrafo(i,j+delta));
            }
            if(posValida(i,j-delta)){
                grafo[posGrafo(i,j)].push_back(posGrafo(i,j-delta));
            }
        }
    }
    int r = Dijkstra(grafo,0);
    if(r!=INF){
        cout << r << endl;
    } else {
        cout << "IMPOSSIBLE\n";
    }

    return 0;
}

