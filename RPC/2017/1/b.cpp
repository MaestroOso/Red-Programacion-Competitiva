#include <bits/stdc++.h>
using namespace std;

bool finR;

int n, o, d;

char tab[30][30] = {{'.'}};
bool visitados[30][30][450]={{{false}}};
int dx[] = {1,1,-1,-1};
int dy[] = {1,-1,1,-1};

int dx2[] = {2,2,-2,-2};
int dy2[] = {2,-2,2,-2};

bool posValida(int x, int y){
    if(x<0 || x >= n){
        return false;
    }
    if(y<0 || y >= n){
        return false;
    }
    return true;
}

char xALetra(int x){
    return (char)(x+'a');
}

string yACadena(int y){
    string res = "";
    if(y<10){
        res+=(y+'0');
    } else if(y >= 10 && y<20){
        char aux = ((y%10)+'0');
        res += '1';
        res+= aux;
    } else{
        char aux = ((y%20)+'0');
        res += '2';
        res+= aux;;
    }
    return res;
}

void recursion(int x, int y, int blancas, set<string> &fichasGanadoras){

    if(finR){
        return;
    }

    visitados[x][y][blancas] = true;

    if(blancas == 0){
        fichasGanadoras.insert(xALetra(d)+yACadena(n-o));
        finR = true;
        return;
    }

    for(int i = 0; i<4; ++i){
        if(posValida(x+dx2[i],y+dy2[i]) && tab[x+dx[i]][y+dy[i]] == 'W' && tab[x+dx2[i]][y+dy2[i]] == '_' && !visitados[x+dx2[i]][y+dy2[i]][blancas-1]){
            tab[x+dx2[i]][y+dy2[i]] = 'B';
            tab[x+dx[i]][y+dy[i]] = '_';
            tab[x][y] = '_';
            recursion(x+dx2[i],y+dy2[i],blancas-1,fichasGanadoras);
            tab[x+dx2[i]][y+dy2[i]] = '_';
            tab[x+dx[i]][y+dy[i]] = 'W';
            tab[x][y] = 'B';
        }
    }

}

int main(){

    string queso;
    scanf("%d",&n);
    int blancas = 0;
    for(int i = 0; i<n; ++i){

        scanf("%30s",&tab[i]);
        for(int j = 0; j<n; ++j){
            if(tab[i][j]=='W') blancas++;
        }
    }

    set<string> fichasGanadoras;
    for(int i = 0; i<n; ++i){
        for(int j = 0; j<n; ++j){
            if(tab[i][j]=='B'){
                o = i; d = j;
                finR = false;
                memset(visitados, false, sizeof visitados);
                recursion(i,j, blancas, fichasGanadoras);
            }
        }
    }

    if(fichasGanadoras.size() == 0){
        printf("None\n");
    } else if(fichasGanadoras.size() > 1){
        printf("Multiple\n");
    } else {
        cout << *(fichasGanadoras.begin()) << endl;
    }
    return 0;
}
