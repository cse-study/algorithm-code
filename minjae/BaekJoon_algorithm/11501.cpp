#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std; 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);

    int t; cin >> t;
    while(t--){
        int n, a;
        vector<int> V;
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> a;
            V.push_back(a);
        }
        int max_v = V[n-1];
        long long res = 0;
        for(int i= n-2; i>=0; i--){
            if(V[i] > max_v)    max_v = V[i];
            res += max_v - V[i]; // 뒤에서부터 max 갱신하며 O(n)에 완료가능
        }
        cout << res << '\n';
    }
    return 0;
}