#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);

    vector<int> V;
    int n1,n2,a; cin >> n1;
    for(int i=0; i<n1; i++){
        cin >> a;
        V.push_back(a);
    }
    sort(V.begin(), V.end());

    cin >> n2;
    for(int i=0; i<n2; i++){
        cin >> a;
        cout << upper_bound(V.begin(), V.end(), a) - lower_bound(V.begin(), V.end(), a) << '\n'; 
        // a 초과 - a 이상 = a의 갯수(binary search 도움 bound함수들사용하면, 정렬된 자료구조안에서 몇이상 몇이하 갯수 빠르게 찾아낼수 있음)
    }
    return 0;
}