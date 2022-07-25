#include <iostream>
using namespace std;

char board[2200][2200]; //3^7 -> 2150

void fun(int n, int x, int y){
    if(n ==1){
        board[x][y] = '*';
        return;
    }
    for(size_t i=0; i<3; i++){
        for(size_t j=0; j<3; j++){
            if(i==1 && j==1)    continue; // middle is empty
            fun(n/3, x + n/3*i, y+n/3*j); // fill 8칸(except middle) 
        }
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;
    for(size_t i=0; i<n; i++){
        fill(board[i], board[i] + n, ' '); // fill empty val
    }
    fun(n,0,0);
    for(size_t i=0; i<n; i++){
        cout << board[i] << '\n';
    }
}