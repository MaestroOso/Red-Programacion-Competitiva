#include <bits/stdc++.h>
using namespace std;
//#define ii pair<int,long long int>
typedef long long int ull;
#define foi(j,a,b) for(int i = j; i<a; i+=b)

ull n, fin, ini;
int k;
ull uno = 1;
int busquedaBin(vector<pair<ull,ull> > &parejas, int i){
    int lo=0, hi=i-1, mid;
    for(int x = 0; x<50; ++x){
        mid = (hi+lo)/2;


        if(parejas[i].second > parejas[mid].first){
            if(parejas[i].second > parejas[mid+1].first){
                lo = mid+1;
            } else {
                return mid;
            }
        } else{
            hi = mid-1;
        }
    }
    return -1;
}

int main()
{
    cin >> n >> k;
    /** Posicion_Fin     Posicion_Inicio **/
    vector<pair<ull,ull> >parejas(k);
    for(int i = 0; i<parejas.size(); ++i){
        cin >> ini >> fin;
        parejas[i].first = fin;
        parejas[i].second = ini;
    }
    sort(parejas.begin(),parejas.end());
    vector<ull> dp(k);
    dp[0] = (parejas[0].first - parejas[0].second + uno);
    for(int i = 1; i<parejas.size(); ++i){
        int bs = busquedaBin(parejas,i);
        if(bs!=-1){
            dp[i] = (parejas[i].first - parejas[i].second + uno) + dp[bs];

        } else{
            dp[i] = (parejas[i].first - parejas[i].second + uno);

        }
        dp[i] = max(dp[i],dp[i-1]);

    }

    cout << n - dp[k-1] << endl;
    return 0;
}
