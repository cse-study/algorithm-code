#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n,D[100001],a[100001];
    cin >> n;
    for(size_t i=1; i<=n; i++){
        cin >> a[i];
        D[i] = a[i];
    }
    
    for(size_t i=1; i<=n; i++){
        D[i] = max(D[i],D[i-1]+a[i]); // nested for loop is timeover, so i use 1 for loop
    }
    cout << *max_element(D+1,D+n+1);
}