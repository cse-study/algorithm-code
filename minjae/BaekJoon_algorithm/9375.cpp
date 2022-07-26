#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;  

int t,n;
string name, clo;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        cin >> n;
        int ans=1;
        unordered_map<string, int> M; // while안에서 초기화
        for(int i=0; i<n; i++){
            cin >> name >> clo;
            M[clo]++;
        }
        for(auto i : M) ans *= i.second + 1; // 선택안하는 경우 + 옷종류의 갯수
        cout << ans - 1 << '\n'; // 아무것도 안입은거는 제외
    }

}
    