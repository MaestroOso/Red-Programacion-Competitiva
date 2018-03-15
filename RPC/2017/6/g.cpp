#include <bits/stdc++.h>
using namespace std;

int mat[501][501], orden[501];
int n;

long long int floydWarshall()
{
    long long int res = 0;
    int x, y, z;

    for(int k = 0; k < n; ++k)
    {
        z = orden[k];
        for(int i = 0; i < n; ++i)
        {
            x = orden[i];
            for(int j = 0; j < n; ++j)
            {
                y = orden[j];
                mat[x][y] = min(mat[x][y], mat[x][z] + mat[z][y]);
            }
        }

        for(int i = 0; i <= k; ++i)
        {
            x = orden[i];
            for(int j = 0; j <= k; ++j)
            {
                y = orden[j];
                res += mat[x][y];
            }
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 0; i<n; ++i)
        {
            for(int j = 0; j<n; ++j)
            {
                cin >> mat[i][j];
            }
        }
        for(int i = n-1; i>=0; i--)
        {
            cin >> orden[i];
        }
        cout << floydWarshall() << endl;
    }

    return 0;
}
