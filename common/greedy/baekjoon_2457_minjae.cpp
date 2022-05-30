#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 
//스케쥴 최대갯수 문제와 비슷, 하지만 날짜가 276일이라 시간제한은 더 넉넉해 while 안 for 사용가능

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);

    int n; cin >> n;
    int sm,sd,em,ed;
    vector<pair<int,int> > V;
    for(int i =0; i<n; i++){
        cin >> sm >> sd >> em >> ed;
        V.push_back(pair<int,int>(100*sm+sd, 100*em+ed)); // 날짜는 비교만 가능
    }

    sort(V.begin(), V.end());
    int cnt=0;
    int day = 301; // 1월 0일부터 시작

    while(day < 1201){
        int modify_day = day;
        for(int i=0; i<n; i++){
            if(V[i].first <= day && V[i].second > modify_day) modify_day = V[i].second;
        }
        if(day == modify_day){ // 변한게 없다 -> 불가능하다
            cout << 0;
            return 0;
        }
        cnt++;
        day = modify_day;
    }

    cout << cnt;
    return 0;
}