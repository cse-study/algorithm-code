#include <iostream>
using namespace std;  // dp로 푼다. 

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    int n,m,start,end;
    cin >> n >> m;

    int arr[n+1],D[n+1];
    for(size_t i=1; i<=n; i++)
        cin >> arr[i];
    D[0] = 0;
    D[1]=arr[1];
    for(size_t i=2; i<=n; i++){
        D[i] = D[i-1] + arr[i];
    }

    while(m--){
        cin >> start >> end;
        cout << D[end] - D[start -1] << '\n';
    }
}
    