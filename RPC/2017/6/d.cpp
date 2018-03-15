#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define vi vector<ll>
#define INF 1000000001

struct segmentTree{
    /**Altura del arbol 2^(log(n)+1)  -- 2n
        A valores de verdad
        st segment tree
    **/
    vi st, A;
    int n;

    int left(int p){
        return p<<1;
    }

    int right(int p){
        return (p<<1)+1;
    }

    void build(int p,int L, int R){
        if( L == R){
            st[p] = L;
            return;
        }
        int mid = (L+R)/2;
        build(left(p), L, mid);
        build(right(p), mid+1, R);
        int p1 = st[left(p)];
        int p2 = st[right(p)];
        st[p] = A[p1] <= A[p2] ? p1 : p2;
    }

    segmentTree(vi A_){
        A = A_;
        n = A.size();
        st.assign(4*n,0);
        build(1,0,n-1);
    }

    int rmq(int i, int j){
        return rmq(0,n-1,1,i,j);
    }

    int rmq(int L, int R, int p, int limIzq, int limDer){
        //cout << "L, R "<<L << " " << R << endl;
        if(limIzq > R || limDer < L){
            //cout << "Fuera\n";
            return INF;
        }
        if(L >= limIzq && R <= limDer){
            //cout << "Dentro\n";
            return st[p];
        }
        /**
            Recursion otra vez
        **/

        int mid = (L+R)/2;
        int indiceIzq = rmq(L, mid, left(p), limIzq, limDer);
        int indiceDer = rmq(mid+1, R,right(p), limIzq, limDer);

        if(indiceIzq == INF){
            //cout << "INF1\n";
            return indiceDer;
        } else if(indiceDer == INF){
            //cout << "INF2\n";
            return indiceIzq;
        }
        //cout << "Pregunta\n";
        return A[indiceIzq] < A[indiceDer] ? indiceIzq : indiceDer;

    }

    void imprimir(){
        for(int i = 1; i<st.size(); i++){
            cout << st[i] << " ";
        }
        cout << endl;
    }
};

ll derecha(segmentTree &st, vector<ll> &h, vector<ll> &x, int p){
    ll res = 0;
    if(p == h.size()-1){
        return 0;
    }
    int pn = st.rmq(p+1, h.size()-1);
    res = x[pn] - x[p];
    res*= min(h[p],h[pn]);
    return res + derecha(st,h,x,pn);
}

ll izquierda(segmentTree &st, vector<ll> &h, vector<ll> &x, int p){
    ll res = 0;
    if(p == 0){
        return 0;
    }
    int pn = st.rmq(0, p-1);
    res = x[p] - x[pn];
    res*= min(h[p],h[pn]);
    return res + izquierda(st,h,x,pn);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n;
    long long a;
    cin >> t;
    while(t--){
        cin >> a >> n;
        vector<ll> h(n+1), hAux(n+1); vector<ll> x(n+1, 0);
        for(int i = 1; i<x.size(); ++i){
            cin >> x[i];
            x[i]+=x[i-1];
        }
        for(int i = 0; i<h.size(); ++i){
            cin >> h[i]; hAux[i]=-1*h[i];
        }
        segmentTree st(hAux);
        int o=0, d=hAux.size()-1;

        int inicio = st.rmq(o,d);
        ll de = derecha(st,h,x,inicio);
        ll iz = izquierda(st,h,x,inicio);
        ll res = (de+iz)*a;
//        cout << de << " " << iz << " " << res << endl;
        cout << res << endl;
    }
    return 0;
}
