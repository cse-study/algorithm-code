#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set> // 중복되는 사람 없음으로, 중복가능은 multiset
using namespace std; // 이분탐색, 투포인터도 가능하지만 예외처리 까다로움


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);

    int n; cin >> n;
    string name, log;
    unordered_set<string> S;

    while(n--){
        cin >> name >> log;
        if(log == "enter")  S.insert(name);
        else                S.erase(name);
    }

    vector<string> V(S.begin(), S.end());
    sort(V.begin(), V.end());
    reverse(V.begin(), V.end());
    for(auto i : V) cout << i << '\n';

    return 0;
}