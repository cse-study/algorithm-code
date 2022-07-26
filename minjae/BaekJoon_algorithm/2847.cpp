#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std; 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    
    int n; cin >> n;
    int a, ans=0;
    vector<int> V;
    for(int i=0; i<n; i++){
        cin >> a;
        V.push_back(a);
    }
    int val = V[n-1];
    for(int i=n-2; i>=0; i--){
        if(V[i] >= val){
            while(V[i] >= val){
                V[i]--;
                ans++;
            }
        }
        val = V[i];
    }
    cout << ans;
    return 0;
}