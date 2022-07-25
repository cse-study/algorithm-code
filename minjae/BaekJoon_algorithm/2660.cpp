#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> adj[52];
int vis[52];
int n;

int bfs(int st){
    queue<int> q;
    q.push(st);
    vis[st] = 0;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(auto nxt : adj[cur]){
            if(vis[nxt] >= 0) continue;
            q.push(nxt);
            vis[nxt] = vis[cur] + 1;
        }
    }
    return *max_element(vis+1,vis+n+1);
}

int main(){
    cin >> n;
    while(1){
        int a,b;
        cin >> a >> b;
        if(a == -1 && b == -1)  break;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    int score[n+1], person[n+1];
    priority_queue<pair<int, int> > pq;
    fill(vis+1, vis+n+1, -1);
    for(int i=1; i<=n; i++){
        pq.push(make_pair(bfs(i),i));
        fill(vis+1, vis+n+1, -1); // initilize vis;
    }
    
    for(int i=1; i<=n; i++){
        score[i] = pq.top().first;
        person[i] = pq.top().second;
        pq.pop();
    }

    int num=1;
    for(int i=n; i>=1; i--){
        if(score[i] == score[i-1])  num++;
        else                        break;
    }
    cout << score[n] << " " << num << '\n';
    for(int i=n; i>=n-num+1; i--){
        cout << person[i] << " ";
    }
    return 0;
}