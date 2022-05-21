#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);

    int n; cin >> n;
    int st,end;
    vector<pair<int,int> > V;
    for(int i=0; i<n; i++){
        cin >> st >> end;
        V.push_back(pair<int,int>(st,1));
        V.push_back(pair<int,int>(end,-1));
    }
    sort(V.begin(), V.end());
    
    int ans=0, cur =0, idx = 0;
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