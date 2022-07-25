#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);

    // 정렬 전과 후의 인덱스 차가 가장 큰 값+1
    // = 정렬을 통해 이동한 거리

    int N,num; cin >> N;
    vector<pair<int,int> > A;
    
    for(int i=0; i<N; i++){
        cin >> num;
        A.push_back(pair<int,int>(num,i));
    }

    sort(A.begin(), A.end());
    int res = 0;
    for(int i=0; i<N; i++){
        if(A[i].second - i >=0) res = max(res, abs(i-A[i].second));
    }
    cout << res + 1; // res+1 은 3 번째에서 실패라는 말은 2번째까지 성공했다는 뜻이기때문

    return 0;
}