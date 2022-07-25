#include <iostream>
using namespace std; // O(2^1515)? that's nono... let's think DP


int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    
    // 15 = 3*5
    // 5-> the num's first position is 5 or 0, 3-> sum of each position is divided by 3
    int D[3][1516]={0}; // D[i][j] is j place value, i is residual val divided by 3.
    D[0][2] = 1; // 15
    D[1][2] = 1; // 55
    D[2][2] = 0;

    // 15 -> 115, 515. residual 0 make residual 1 and 2
    // 55 -> 155, 555 residual 1 make residual 0 and 2
    for(size_t i=3; i<=n; i++){
        D[0][i] = (D[1][i-1] + D[2][i-1])%1000000007; 
        D[1][i] = (D[0][i-1] + D[2][i-1])%1000000007;
        D[2][i] = (D[0][i-1] + D[1][i-1])%1000000007;
    }
    cout << D[0][n]; // %15 == 0 os residual 0 
}