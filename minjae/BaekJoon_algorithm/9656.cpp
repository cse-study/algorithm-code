#include <iostream>
using namespace std; // using dp

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    int n;
    bool D[1001];
    cin >> n;
    
    D[1] = false;
    for(size_t i=2; i<=n; i++){
        D[i] = !D[i - 1]; // 하나 빼고 생각하면 승패가 n이 1증가할때마다 바뀐다
    }
    if(D[n]==true)  cout << "SK";
    else            cout << "CY";

}