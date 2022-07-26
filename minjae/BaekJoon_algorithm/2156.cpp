#include <iostream>
#include <algorithm>
using namespace std;  // dp로 푼다. 

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    int n;
    cin >> n;
    int arr[10001],D[10001];
    for(size_t i=1; i<=n; i++)
        cin >> arr[i];
    
    D[1]=arr[1];
    D[2]=arr[1]+arr[2];
    for(size_t i=3; i<=n; i++){
        D[i] = max({D[i-1], D[i-2]+arr[i], D[i-3]+arr[i-1]+arr[i]}); // 3가지중 최대인걸로 갱신
        // D[i-1]이 있는 이유는 i번째에 안마셔도 되기 때문이다.
    }
    cout << D[n];
}