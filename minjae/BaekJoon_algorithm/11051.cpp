#include <iostream>
#include <algorithm>
using namespace std;  // dp로 푼다. 

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    int n,k;
    cin >> n >> k;
    long long D[1001][1001];

    for(size_t i=1; i<=n; i++){ // 조합을 dp로 구현
        D[i][0] = D[i][i] = 1;
        for(size_t j=1; j<i; j++){
            D[i][j] = (D[i-1][j] + D[i-1][j-1])%10007;
        }
    }

    cout << D[n][k] << '\n';
}