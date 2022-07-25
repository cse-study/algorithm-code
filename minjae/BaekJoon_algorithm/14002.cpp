#include <iostream>
#include <algorithm>
#include <deque>
using namespace std; // using dp

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, arr[1003] = {0}, D[1003] = {1}, pre[1003];
    cin >> n;
    
    for(size_t i=1; i<=n; i++){
        cin >> arr[i];
    }
    
    for(size_t i=1; i<=n; i++){
        for(size_t j=1; j<i; j++){
            if(arr[j] < arr[i] && D[i] < D[j]+1){
                D[i] = D[j]+1; 
                pre[i]= j; // 원소 출력위해 경로를 연결시키는 작업
            }
        }
    }

    int max_index=1, maxD=D[1];
    for(size_t i=1; i<=n; i++){
        if(maxD < D[i]){
            maxD = D[i];
            max_index = i;
        }
    }
    
    deque<int> res;
    int cur = max_index;
    while(cur){
        res.push_front(arr[cur]); // 큰수부터 res에 앞으로 넣어서 먼저들어간것이 뒤에, 즉 큰숫자가 뒤에
        cur = pre[cur]; // 가장큰 길이를 찾으면서 저장해둔 index를 역으로 추적함
    }
    cout << res.size() << '\n';
    for(auto k : res){
        cout << k << " ";
    }
}