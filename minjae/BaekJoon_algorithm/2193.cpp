#include <iostream>
using namespace std;  // dp로 푼다. 끝자리에 0, 01을 둘수있어 피보나치이다.

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    int n;
    cin >> n;
    long long D[91]; // n=90이면 int로는 부족
    D[1]=1;
    D[2]=1;
    for(size_t i=3; i<=n; i++){
        D[i] = D[i-1] + D[i-2];
    }
    cout << D[n];
}