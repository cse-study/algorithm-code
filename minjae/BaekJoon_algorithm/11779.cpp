#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<pair<int,int> > adj[1005]; // {1,2} {3,1} {4,2} ... 이런식으로 하겠다
int d[1005];
int path[1005];
int V,E,st,en;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    cin >> V >> E;
    int u,v,w;
    fill(d,d+V+1,100000000); // 우선 거리를 무한으로 둠
    for(int i=0; i<E; i++){
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(w,v)); // 가중치 우선정렬 할것이기 때문에
    }
    cin >> st >> en;
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq; // 최소힙 {가중치, 다음노드}
    d[st]=0; 

    pq.push(make_pair(d[st],st)); // {0,1} 우선 삽입해준다 {가중치,노드}
    while(!pq.empty()){ // pq가 빌때까지
        auto cur = pq.top(); pq.pop(); // cur은 최단거리, Vertex
        if(d[cur.second] != cur.first)  continue; // 현재 d배열에서 st->cur.second의 최댄거리로 저장된 값 = 방금 pq에서 꺼낸것의 최단거리값 다르면 넘어감
        for(auto nxt : adj[cur.second]){ // 값이 다르다면 탐색시작
            if(d[nxt.second] <= d[cur.second]+ nxt.first)   continue; //조건안만족하면(갱신필요 X) for문 다시돔
            d[nxt.second] = d[cur.second]+ nxt.first;
            pq.push(make_pair(d[nxt.second],nxt.second));
            path[nxt.second]=cur.second; // 어디로 부터 왔는지 경로 저장 (경로를 저장하는 arr)
            
        }
    }

    cout << d[en] << '\n'; // 도착지점까지 최단거리
    vector<int> ans;
    int flow = en; // 끝부터 추가해가면서 vec에 값저장.
    while(flow != st){ // 시작점에서 만나면 끝
        ans.push_back(flow);
        flow = path[flow];
    }
    ans.push_back(flow); // 마지막 시작지점도 추가
    reverse(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for(auto i : ans)   cout << i << " ";

}