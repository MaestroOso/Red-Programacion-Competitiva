#include <bits/stdc++.h>
using namespace std;

void generarTriangulo(vector<vector<long long int> > &tPascal){
    /** Arriba **/
    tPascal[0].push_back(1);
    tPascal[1].push_back(1);
    tPascal[1].push_back(1);

    for(int i = 2; i<60; i++){
        tPascal[i].push_back(1);
        for(int j = 1; j<tPascal[i-1].size(); j++){
            tPascal[i].push_back(tPascal[i-1][j-1] + tPascal[i-1][j]);
        }
        tPascal[i].push_back(1);
    }
    return;
}

void calcular(vector<vector<long long int> > &t, int r, int c){
    int i = c-1, j=0;
    for(int p = 0; p<r-1; p++){
        i++; j++;
    }
    cout << t[i][j] << endl;
}

int main(){
    int t, r, c;
    vector<vector<long long int> > tPascal(60);
    generarTriangulo(tPascal);
    //imprimir(tPascal);
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &r, &c);
        calcular(tPascal, r,c);
    }
    return 0;
}
