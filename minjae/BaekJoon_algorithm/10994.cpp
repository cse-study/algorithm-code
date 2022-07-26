#include <bits/stdc++.h>
using namespace std;
char map2[500][500];

void star(int n, int x, int y){
    if (n==1){
        map2[x][y] = '*';
        return;
    }
    for(int i=x; i<y+4*(n-1)+1; i++){ 
        map2[x][i] = '*';
        map2[x+4*(n-1)][i] = '*';
    }
    for (int i = y; i <x+ 4 * (n - 1) + 1; i++){ 
        map2[i][y] = '*';
        map2[i][y+4*(n-1)] = '*';
    }

    star(n-1,x+2,y+2);
    return;
}

int main(){
    int n;
    cin >> n;

    for (int i = 0; i < 4 * (n - 1) + 1; i++){
        for (int j = 0; j < 4 * (n - 1) + 1; j++){
            map2[i][j] = ' ';
        }
    }

    star(n,0,0);

    for (int i=0; i<4*(n-1)+1; i++){
        for(int j=0; j<4*(n-1)+1; j++){
            cout << map2[i][j];
        }
        cout << '\n';
    }
}