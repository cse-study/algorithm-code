#include <iostream>
using namespace std; // 종이의 개수 문제와 비슷

int board[64][64];

void fun(int x, int y, int n){ 
    if(n == 1){
        cout << board[x][y];
        return;
    }

    bool zero = true, one = true;
    for(size_t i=x; i< x+n; i++){ // check all num is same or not
        for(size_t j=y; j<y+n; j++){
            if(board[i][j])     zero = false; // board[i][j] = 1
            else                one = false; // board[i][j] = 0
        }
    }
    
    if(zero)
        cout << "0"; // all board is same num then cout
    else if (one)
        cout << "1"; // all board is same num then cout

    else{ // if all num is not same, then divide
        int dn = n/2;
        cout << "(";
        for(size_t i=0; i<2; i++){
            for(size_t j=0; j<2; j++){
                fun(x + i*dn, y + j*dn , dn); // divide by 4 parts.
            }
        }
        cout << ")";
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n;
    string str;
    cin >> n;

    for(size_t i=0; i<n; i++){
        cin >> str;
        for(size_t j=0; j<n; j++){
            board[i][j] = str[j] - '0';
        }
    }
    fun(0,0,n);
}