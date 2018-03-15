#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    long long int n, k, res, seis=6;
    cin >> t;
    while(t--){
        cin >> n >> k;
        res = n+1; seis=6;
        for(int i = 1; i<=k; ++i){
            res+= (seis*(n-i+1));
            seis+=6;
        }
        cout << res << endl;
    }
    return 0;
}
