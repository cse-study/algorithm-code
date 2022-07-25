#include <iostream>
#include <string>
#include <tuple>
#include <set>
#include <bits/stdc++.h>
// 그리디로 접근, 가격이 가장 높은 가격이 들어갈수 있는 가방중 무게가 젤 작은 가방부터 처리해준다.

using namespace std;
pair<int, int> jewel[3000003];
multiset<int> bag;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    int n,k,c;
    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> jewel[i].second >> jewel[i].first;
    }
    sort(jewel, jewel+n);
    for(int i=0; i<k; i++){
        cin >> c;
        bag.insert(c);
    }

    long long ans=0;

    for(int i=n-1; i>=0; i--){
        int m,v;
        tie(v,m) = jewel[i]; // first, second를 tie로 한번에 받음
        auto it = bag.lower_bound(m); // 가방에서 jewel의 맨뒤(가장 가치가 높은) 것보다 가방무게 널널한것부터 it시작
        if(it == bag.end()) continue; //찾을수 없는 경우(무개가 커서 넣을수 있는 가방이 없다.)
        ans += v; // 가치를 더해줌
        bag.erase(it);
    }
    cout << ans;
}