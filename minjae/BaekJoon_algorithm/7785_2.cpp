#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;  

unordered_set<string> S;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    int n; cin >> n;
    string A,B;
    for(int i=0; i<n; i++){
        cin >> A >> B;
        if(B == "enter") S.insert(A);
        else             S.erase(A);
    }
    vector<string> Ans(S.begin(), S.end());
    sort(Ans.begin(), Ans.end());
    reverse(Ans.begin(), Ans.end());
    for(auto i : Ans) cout << i << '\n';
}
    