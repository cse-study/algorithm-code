#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; // using dp

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n,D[1001]={0};
    vector <int> V(10001,0);

    cin >> n;

    V.push_back(0);
    for(size_t i=1; i<=n; i++){
        cin >> V[i];
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            D[i] = max(D[i], D[i-j]+V[j]); 
            // 결국 D[3] = D[2] + V[1], D[1] + V[2], D[0] + V[3] 중에 max select
        }
    }
    cout << D[n];
}