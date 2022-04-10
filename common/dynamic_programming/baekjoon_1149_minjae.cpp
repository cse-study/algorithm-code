#include <iostream>
using namespace std;  // dp로 푼다.

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    // D[i][0] = i 번째 집까지 칠할 때 비용의 최솟값, i번째 집은 빨강
    int D[1001][3];
    int n,sum=0;
    cin >> n;
    int R[1001],G[1001],B[1001];
    for(size_t i=1; i<=n; i++){
        cin >> R[i];
        cin >> G[i];
        cin >> B[i];
    }
    D[1][0] = R[1];
    D[1][1] = G[1];
    D[1][2] = B[1];
    for(size_t i=2; i<=n; i++){
        D[i][0] = min(D[i-1][1],D[i-1][2]) + R[i];
        D[i][1] = min(D[i-1][0],D[i-1][2]) + G[i];
        D[i][2] = min(D[i-1][0],D[i-1][1]) + B[i];
    }
    cout << min(min(D[n][0],D[n][1]),D[n][2]);
}
    