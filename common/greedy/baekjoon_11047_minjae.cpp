#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);

    vector<int> v;
    int coin;
    int n,k; cin >> n >> k;
    
    for(int i=0; i<n; i++){
        cin >> coin;
        v.push_back(coin);
    }

    reverse(v.begin(), v.end());
    int ans=0;
    for(int i=0; i<n; i++){
        ans += k / v[i]; // 나눠진다 -> 가능 (큰순서로 정렬되어있음)
        k %= v[i]; // 돈을 쓰고 남은 나머지가 다시 목표값
    }
    cout << ans << '\n';

    return 0;
}