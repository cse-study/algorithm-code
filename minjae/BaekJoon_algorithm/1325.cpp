#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> adj[10002];
int vis[10002];
int n,m;

int bfs(int st){
    int num=0;
    queue<int> q;
    q.push(st);
    vis[st]=0;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(auto nxt : adj[cur]){
            if(vis[nxt] >= 0)    continue;
            vis[nxt] = vis[cur] +1;
            q.push(nxt);
        }
    }
    for(int i=1; i<=n; i++){
        if(vis[i] >= 0) num++;
    }
    return num;
}

int main(){
    cin >> n >> m;
    while(m--){
        int a,b;
        cin >> a >> b;
        adj[b].push_back(a); // directed graph
    }

    fill(vis, vis+n+1, -1);
    int score[n+1], index[n+1];
    vector<pair<int, int> > res;
    priority_queue<pair<int, int> > pq;
    for(int i=1; i<=n; i++){
        res.push_back(make_pair(bfs(i),i));
        fill(vis, vis+n+1, -1);
    }

    sort(res.begin(), res.end());
    reverse(res.begin(), res.end());

    int num=1;
    for(int i=0; i<n-1; i++){
        if(res[i].first == res[i+1].first)  num++;
        else    break;
    }
    for(int i=num-1; i>=0; i--){
        cout << res[i].second << " ";
    }

    return 0;
}