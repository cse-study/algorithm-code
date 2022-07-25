#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 

//현재 시간에서 열리는 강의갯수가 최대인것. 즉 어떤 시점에서 강의의 갯수가 최대인것 -> 강의실의 갯수

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);

    int n; cin >> n;
    int st,end;
    vector<pair<int,int> > V;
    for(int i=0; i<n; i++){
        cin >> st >> end;
        V.push_back(pair<int,int>(st,1)); // 강의가 시작하면 1개증가
        V.push_back(pair<int,int>(end,-1)); // 강의가 끝나면 강의실 갯수 1개 감소
    }
    sort(V.begin(), V.end());
    
    int ans=0, cur =0, idx = 0; // 답, 현재시간에서 열린 강의실갯수, idx
    int curtime = V[0].first; // 가장 빠른 수업 시작시간

    while(1){
        while(idx < 2*n && V[idx].first == curtime){
            cur += V[idx].second;
            idx++;
        }
        ans = max(ans, cur);
        if(idx == 2*n)  break;
        curtime = V[idx].first;
    }
    cout << ans;
    return 0;
}