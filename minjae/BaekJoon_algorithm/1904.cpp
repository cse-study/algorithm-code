#include <iostream>
#include <vector>

using namespace std; // using dp

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    long long D[1000001]={0};
    cin >> n;

    D[1] =1;
    D[2] = 2;
    for(size_t i=3; i<=n; i++){
        D[i] = (D[i-1] + D[i-2])%15746;
    }
    cout << D[n];
}