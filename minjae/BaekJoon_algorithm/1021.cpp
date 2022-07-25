#include <iostream>
#include <deque> // 양방향 순환 큐 -> 덱이라고 생각 가능 
// STL 덱은 특정위치 추가 제거 가능하게 구현되어 있음.
using namespace std;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n,m,count(0);
    cin >> n >> m;
    int now = n;

    deque<int> D;
    int arr[m];

    for(size_t i=1; i<=n; i++){ // 1,2,3, ... n, 1, 2, 3, ... n (2n개 덱에 넣음)
        D.push_back(i);
        D.push_front(11-i);
    }

    cout << D[n] << endl;

    for(size_t i=0; i<m; i++){
        int k;
        cin >> k;
        if(now+1-k >= k-1){ //중간에서 앞, 뒤로 k를 갈수있는데 앞까지 가는게 더 멀경우, 뒤로(즉 2번사용)
            count += k-1;
            D.erase(D.begin()+ n+k-1);
            now;
        }
        else{
            count += now+1-k;
            D.erase(D.begin()+ k-1);
        }
    }
    cout << count;
}