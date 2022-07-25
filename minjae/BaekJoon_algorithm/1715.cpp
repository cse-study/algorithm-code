#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

// 허프만 코딩 압축 방식이랑 같다.
using namespace std;
priority_queue<int, vector<int>, greater<int> > pq; // 최소힙

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    int n,c; cin >> n;
    for(int i=0; i<n; i++){
        cin >> c;
        pq.push(c);
    }
    int ans = 0;
    while(pq.size() > 1){ // 끝에 추가하고 끝나기때문에 1개면 끝난것이다.
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        ans += a + b;
        pq.push(a+b);
    }
    cout << ans;
}