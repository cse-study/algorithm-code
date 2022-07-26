#include <iostream>
using namespace std;

char board[3080][6160]; //3^2^10 -> 3072

void fill(int x,int y){ // make triangle
    board[x][y] = '*';
    board[x+1][y-1] = '*', board[x+1][y+1] = '*';

    for(size_t i=y-2; i<=y+2; i++){
        board[x+2][i] = '*';
    }
}

void fun(int n, int x, int y){ // using recursion
    if(n == 3){
        fill(x,y);
        return;
    }
    int ns = n/2;
    fun(ns,x,y);
    fun(ns, x+ns, y-ns); // down by ns, left by ns
    fun(ns, x+ns, y+ns); // down by ns, right by ns
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n;
    cin >> n;
    fun(n,0,n-1);
    for(size_t i=0; i<n; i++){
        for(size_t j=0; j<2*n-1; j++){
            if(board[i][j]=='*')    cout << "*";
            else                    cout << " ";
        }
        cout << '\n';
    }
}