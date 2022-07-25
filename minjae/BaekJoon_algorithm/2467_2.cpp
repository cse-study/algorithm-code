#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std; 

int n,a;
vector<int> V;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a;
        V.push_back(a);
    }
    
    int ans1= 1e9+1, ans2 = 1e9+1;
    for(int i=0; i<n; i++){ // -V[i]에대해 lower_bound를 구할예정 처음으로 -V[i]이상이 나오는 위치
        // idx로부터 앞,뒤,자신의 V와 비교하며, 최솟값을 있는지 확인하면서 갱신
        int idx = lower_bound(V.begin(), V.end(), -V[i]) - V.begin();
        if(idx+1 < n && i != idx+1 && abs(V[i] + V[idx+1]) < abs(ans1+ ans2)){
            ans1 = V[i];
            ans2 = V[idx+1];
        }
        if(idx < n && i != idx && abs(V[i] + V[idx]) < abs(ans1 + ans2)){
            ans1 = V[i];
            ans2 = V[idx];
        }
        if(idx != 0 && i != idx-1 && abs(V[i] + V[idx-1]) < abs(ans1 + ans2)){
            ans1 = V[i];
            ans2 = V[idx-1];
        }
    }
    if(ans1 > ans2) cout << ans2 << " " << ans1;
    else            cout << ans1 << " " << ans2;

    return 0;
}