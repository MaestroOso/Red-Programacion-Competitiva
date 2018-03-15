#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    string a;
    cin >> t;
    while(t--)
    {
        cin >> a;
        if(a.size() == 1)
        {
            if(a == "0"){
                printf("1\n");
                continue;
            } else if(a == "1"){
                printf("66\n");
                continue;
            }
        }
        if(a[a.size()-1]=='0' || a[a.size()-1]=='5')
        {
            printf("76\n");
        }
        else if(a[a.size()-1]=='1' || a[a.size()-1]=='6')
        {
            printf("16\n");
        }
        else if(a[a.size()-1]=='2' || a[a.size()-1]=='7')
        {
            printf("56\n");
        }
        else if(a[a.size()-1]=='3' || a[a.size()-1]=='8')
        {
            printf("96\n");
        }
        if(a[a.size()-1]=='4' || a[a.size()-1]=='9')
        {
            printf("36\n");
        }
    }
    return 0;
}
