#include <bits/stdc++.h>
using namespace std;

unsigned long long int invertir = 0;
const int INF = 10000026;

void mergeA(vector<int> &A, int p, int q, int r){
    int n1 = q-p+1;
    int n2 = r-q;
    int i, j, k;
    vector<int> L(n1+2,INF);
    vector<int> R(n2+2,INF);
    for(i = 1; i<=n1; i++){
        L[i] = A[p+i-1];
    }
    for(j = 1; j<=n2; j++){
        R[j] = A[q+j];
    }
    L[n1+1] = INF;
    R[n2+1] = INF;
    i = 1;
    j = 1;
    for(k = p; k<=r; k++){
        if(L[i] < R[j]){
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
            invertir = invertir + n1 - i +1;
        }
    }
}

void mergeSort(vector<int>&A, int p, int r){
    if(p<r){
        int q = (p+r)/2;
        mergeSort(A,p,q);
        mergeSort(A,q+1,r);
        mergeA(A,p,q,r);
    }
}

int main()
{
    int t, x;
    while(scanf("%d", &t)){
        if(t == 0) break;
        vector<int> A(t+1);
        for(int i = 1; i<=t; i++){
            scanf("%d", &A[i]);
        }
        invertir = 0;
        mergeSort(A,1,t);
        cout << invertir << "\n";
    }
    return 0;
}
