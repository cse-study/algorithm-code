#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std; 

long long reverseint(string s){
    reverse(s.begin(), s.end());
    long long s2 = stoll(s); // int 가아닌 long long 으로 stoll임 ㅠㅠㅠ
    return s2;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);

    int n; cin >> n;
    string s;
    vector<long long> V;

    for(int i=0; i<n; i++){
        cin >> s;
        long long result = reverseint(s);
        V.push_back(result);
    }

    sort(V.begin(), V.end());
    for(auto k : V) cout << k << '\n';

    return 0;
}