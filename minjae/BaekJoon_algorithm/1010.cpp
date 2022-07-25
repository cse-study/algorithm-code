#include <iostream>
#include <algorithm>
using namespace std;  // dp로 푼다. 

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    int c,n,k;
    cin >> c;
    int D[32][32];

    for(size_t i=1; i<=31; i++){ // 조합을 dp로 구현
        D[i][0] = D[i][i] = 1;
        for(size_t j=1; j<i; j++){
            D[i][j] = D[i-1][j] + D[i-1][j-1];
        }
    }

    while(c--){
        cin >> k >> n;
        cout << D[n][k] << '\n';
    }
    
}