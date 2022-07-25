#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);

    string s;
    cin >> s;

    vector<string> V;
    for(int i=0; i<s.size(); i++){
        string result = "";
        for(int j=i; j<s.size(); j++){
            result += s[j];
        }
        V.push_back(result);
    }
    
    sort(V.begin(), V.end());
    for(auto i : V) cout << i << '\n';

    return 0;
}