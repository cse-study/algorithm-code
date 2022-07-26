#include <iostream> 
#include <stack>// using stack
#include <utility>
using namespace std;


int main(){
    ios_base::sync_with_stdio(0); //시간초과 나서 넣음
    cin.tie(0);
    stack<pair<int,int>> tower;
    int n;
    cin >> n;

    tower.push({100000001, 0}); // 높이 기준

    for(size_t i=1; i<=n; i++){ // 몇번쨰인지를 나타내는 i를 출력할것이기 떄문에 i=i
        int h;
        cin >> h;
        while(tower.top().first < h) 
            tower.pop();
        cout << tower.top().second << " ";
        tower.push({h,i}); 
    }
}
