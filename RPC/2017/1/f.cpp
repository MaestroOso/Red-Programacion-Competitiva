#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k, floor;
    string res;


    cin >> n >> k;
    int masAltoSafe=1, masBajoBroken = k;

    for(int i = 0; i<n; ++i)
    {
        cin >> floor >> res;
        if(res=="SAFE")
        {
            masAltoSafe = max(masAltoSafe, floor);
        }
        else
        {
            masBajoBroken = min(masBajoBroken, floor);
        }
    }

    if(masBajoBroken-masAltoSafe<=1)
    {
        cout << masBajoBroken<< " " << masAltoSafe << endl;
    }
    else
    {

        cout << masAltoSafe+1 << " " << masBajoBroken-1 << endl;
    }
    return 0;
}

