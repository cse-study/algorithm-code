#include <iostream>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

class cmp{ // pq는 bool 함수가 아닌 class 로 cmp를 구현해야 한다. pq는 컨테이너이기 때문.
    public:
    bool operator() (int a, int b){
        if(abs(a) != abs(b))    return abs(a) > abs(b); // 앞의 abs가  크면 true // 절댓값 작은것이 왼쪽으로 정렬하겠다
        return a>0 && b <0; // 절댓값이 같은 경우는 a가 양수고 b가 음수일때만 True 아니면 False
    }
};

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    priority_queue<int, vector<int>, cmp> pq; // 기본은 최대힙이고 우린 절댓값 작은것이 기준이다. 
    int n,k; cin >> n;
    for(int i=0; i<n; i++){
        cin >> k;
        if(k == 0){
            if(pq.empty())  cout << 0 << '\n'; // 빈것인지 확인해줘야 함
            else{
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else{
            pq.push(k);
        }
    }
}