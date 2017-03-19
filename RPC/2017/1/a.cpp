#include <bits/stdc++.h>
using namespace std;

int h, w, b;
int mat[101][101]= {{0}};
int suma[101][101]= {{0}};

int dx[] = {0,1,0,1,-1,0,-1,1,-1};
int dy[] = {0,0,1,1,0,-1,-1,-1,1};

int sumCoso(int i, int j)
{
    int a, b;
    if(i<0)
    {
        a = h-1;
    }
    else if(i>h-1)
    {
        a = 0;
    }
    else
    {
        a=i;
    }
    if(j<0)
    {
        b=w-1;
    }
    else if(j>w-1)
    {
        b = 0;
    }
    else
    {
        b=j;
    }
    return mat[a][b];
}

int main()
{

    cin >> w >> h >> b;
    for(int i = 0; i<h; ++i)
    {
        for(int j =0; j<w; ++j)
        {
            cin >> mat[i][j];
        }
    }

    for(int x = 0; x<b; ++x)
    {

        for(int i = 0; i<h; ++i)
        {
            for(int j =0; j<w; ++j)
            {
                int s = 0;
                for(int p = 0; p<9; ++p)
                {
                    s+= sumCoso(i+dx[p],j+dy[p]);
                }
                //cout << s << endl;
                suma[i][j] = s;
            }
        }

        for(int i = 0; i<h; ++i)
        {
            for(int j =0; j<w; ++j)
            {
                mat[i][j] = suma[i][j];
            }
        }

    }
    set<int> diferentes;
    for(int i = 0; i<h; ++i)
    {
        for(int j =0; j<w; ++j)
        {
            //cout << mat[i][j] << " ";
            diferentes.insert(mat[i][j]);
        }
        //cout << endl;
    }
    cout << diferentes.size() << endl;

    return 0;
}

