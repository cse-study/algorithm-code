#include <iostream>
using namespace std; // using recursion

int board[2200][2200];
int res[3];

bool check(int x, int y, int n){
    for(size_t i=x; i< x+n; i++){ 
        for(size_t j=y; j<y+n; j++){
            if(board[x][y] != board[i][j]) // check n*n board is same num or not.
                return false;
        }
    }
    return true;
}

void fun(int x, int y, int n){ 
    if(check(x,y,n)){
        res[board[x][y]+1] +=1; // -1 save in res[0], 0 save in res[1]..
        return;
    }
    int dn = n/3;
    for(size_t i=0; i<3; i++){
        for(size_t j=0; j<3; j++){
            fun(x + i*dn, y + j*dn , dn); // divide by 9 parts.
        }
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n;
    cin >> n;

    for(size_t i=0; i<n; i++){
        for(size_t j=0; j<n; j++){
            cin >> board[i][j];
        }
    }

    fun(0,0,n);
    for(auto k : res)
        cout << k << '\n';
    
}