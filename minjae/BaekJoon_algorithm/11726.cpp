#include <iostream>
using namespace std;  // dp로 푼다. 피보나치이다.

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    int n, D[1001];
    cin >> n;

    D[1] = 1;
    D[2] = 2;
    for(size_t i=3; i<=n; i++)
        D[i] = (D[i-1] + D[i-2])%10007;
    cout << D[n];
}
    