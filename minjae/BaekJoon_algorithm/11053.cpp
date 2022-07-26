#include <iostream>
#include <algorithm>
using namespace std; // soving use dp

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n,D[1001],a[1001];
    cin >> n;
    for(size_t i=1; i<=n; i++){
        cin >> a[i];
    }
    fill(D+1,D+n+1,1);

    for(size_t i=1; i<=n; i++){
        for(size_t j=1; j<i; j++){
            if(a[j] < a[i])
                D[i] = max(D[i],D[j]+1); // 5개 예시로해서 해보면 이해됨
        }
    }

    cout << *max_element(D+1,D+n+1);
}