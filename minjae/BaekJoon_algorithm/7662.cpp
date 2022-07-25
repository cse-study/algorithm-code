#include <iostream>
#include <set>
#include <string>

using namespace std;
// insert erase O(logN) => binary search tree, 삭제최대최소 그냥 트리 루트에서 왼쪽 오른쪽으로 감
//중복허용 -> multiset

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    int t,k; cin >> t;
    while(t--){
        cin >> k;
        multiset<int> MS;
        string C; int I;
        for(int i=0; i<k; i++){
            cin >> C >> I;
            if(C == "I")    MS.insert(I);
            else if(C == "D" && MS.size() == 0)  continue;
            else if(C == "D" && I == 1) MS.erase(prev(MS.end())); // 최댓값 삭제
            else if(C == "D" && I == -1)  MS.erase(MS.begin()); // 최솟값 삭제
        }
        auto it_be = MS.begin();
        auto it_end = MS.end();
        if(MS.size() == 0)  cout << "EMPTY" << '\n';
        else{
            cout << *prev(it_end) << " " << *it_be << '\n';
        }
    }
}