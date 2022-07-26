#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; //dp 는 n2으로 그래도 시간초과, 그리디 떠올림 / 정렬을 먼저하고 추가하는방법을 생각

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);

    vector<pair<int,int> > V;
    int n,a,b; cin >> n;
    for(int i=0; i<n; i++){
        cin >> a >> b;
        V.push_back(pair<int,int>(b,a)); // 끝나는 시간이 빠른것이 중요한 선택! 이걸 기준으로 정렬할것!
    }
    sort(V.begin(),V.end());

    int end_time = 0;
    int cnt = 0;
    for(int i=0; i<n; i++){
        if(end_time > V[i].second)  continue;
        cnt++;
        end_time = V[i].first;
    }
    
    cout << cnt;
    return 0;
}