#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
// mst 알고리즘은 프림 알고리즘으로 구현
vector<pair<int, int> > adj[10005]; // adj[1] 에 여러개 쌓고, adj[2] 에 여러개 쌓을수 있다. 그 원소가 pair인것이다.
// i 정점에 연결된 (가중치,다른정점) -> adj[i] = {가중치,다른정점}
bool chk[10005];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    int v,e; cin >> v >> e;
    for(int i=0; i<e; i++){
        int a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back({make_pair(c,b)}); // cont 기준으로 우선순위큐
        adj[b].push_back(make_pair(c,a));
    }
    
    priority_queue< tuple<int,int,int>, vector<tuple<int,int,int> >, greater<tuple<int,int,int> > > pq; // 비용,정점1,정점2, 최소힙
    // pq 기본선언은 priority_queue<int, vector<int>> pq 이다. 
    chk[1]=1; // 1번부터 시작할것임으로 이미 check포함되어있다고 생각
    for(auto nxt : adj[1])  pq.push({nxt.first, 1, nxt.second}); // 일단 pq에 1번간선과 연결된 모든 정보(비용,정점1,정점2) 추가
    int cnt=0,ans=0;

    while(cnt<v-1){ // vertex 1개 추가하고 시작하여 v-1개 돌면서 v개의 vertex를 가지고 1개씩만 연결된 그래프가 완성
        int cost,a1,b1;
        tie(cost,a1,b1) = pq.top(); pq.pop(); // 현재 pq에서 최소값을 cost,a1,b1으로 지정하고 삭제한다.
        if(chk[b1])  continue; // 이미 연결돼있으면 pass, 아니면 추가 
        ans += cost; // 연결이 안 되어있으니 추가해주고,
        chk[b1]=1; // b1은 연결돼었다고 바꿔줌
        cnt++;
        for(auto nxt : adj[b1]){ // b1과 연결된 간선 탐색
            if(!chk[nxt.second]) // b1과 연결된 다른 간선이, 하나하나 늘려나가는 것애(색칠)안되어 있다면
                pq.push({nxt.first,b1,nxt.second}); // pq에 추가
        }
    }
    cout << ans;

}