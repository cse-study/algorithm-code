#include <iostream>
#include <algorithm>
using namespace std; // using dp

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;
    int D[50001];
    D[1]=1;

    for(size_t i=1; i<=n; i++){
        D[i] = D[1] + D[i-1];
        for(size_t j=2; j*j<=i; j++){
            D[i] = min(D[i], 1+ D[i-j*j]);
        }
    }
    cout << D[n];
}