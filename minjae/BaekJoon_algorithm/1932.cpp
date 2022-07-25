#include <iostream>
#include <algorithm>
using namespace std;  // dp로 푼다. 

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    int n;
    cin >> n;
    int D[501][501], arr[501][501];
    for(size_t i=1; i<=n; i++){
        for(size_t j=1; j<=i; j++){
            cin >> arr[i][j]; // i는 번째줄(상하), j는 번쨰칸(좌우)
        }
    }

    D[1][1] = arr[1][1]; //initial val
    for(size_t i=2; i<=n; i++){
        for(size_t j=1; j<=i; j++){
            D[i][j] = max(D[i-1][j],D[i-1][j-1]) + arr[i][j];
        }
    }
    cout << *max_element(D[n]+1, D[n]+n+1);
}
    