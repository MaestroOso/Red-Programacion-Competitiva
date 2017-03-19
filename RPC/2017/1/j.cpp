#include <bits/stdc++.h>
using namespace std;

#define ii pair<int,int>

int busquedaBinaria(vector<pair<ii, long long int> > &olas, int i){
    int hi = i-1, lo = 0, mid;
    for(int x=0; x<50; ++x){
        mid = (hi+lo)/2;
        if(olas[mid].first.first <= olas[i].first.second){
            if(olas[mid+1].first.first <= olas[i].first.second)
                lo = mid+1;
            else
                return mid;
        } else {
            hi = mid-1;
        }
    }
    return -1;
}

int main(){
    int n, m, w, f;
    long long int ff;
    scanf("%d",&n);
            /** Final Inicio Fun**/
    vector<pair<ii, long long int> > olas(n);
    vector<long long int> respuestas(n,0);
    for(int i = 0; i<n; ++i){
        scanf("%d %d %d", &m, &f, &w);
        ff = (long long int)f;
        olas[i] = make_pair(ii(m+w,m),ff);
    }
    sort(olas.begin(),olas.end());

    respuestas[0] = olas[0].second;
    for(int i = 1; i<n; ++i){
        int actual = olas[i].second;
        int bs = busquedaBinaria(olas,i);
        if(bs!=-1)
            respuestas[i] = actual + respuestas[bs];
        else
            respuestas[i] = actual;
        respuestas[i] = max(respuestas[i], respuestas[i-1]);
    }

    cout << respuestas[n-1] << endl;
    return 0;
}
