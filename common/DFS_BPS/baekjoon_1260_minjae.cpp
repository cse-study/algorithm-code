#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

int n,m,v;
vector<int> adj[1002];
bool vis[1002];

void dfs1(){
    stack<int> s;
    s.push(v);
    while(!s.empty()){
        int cur = s.top();
        s.pop();
        if(vis[cur])    continue;
        vis[cur] = true;
        cout << cur << " ";
        for(int i=0; i<adj[cur].size(); i++){
            // stack input should be reverse sequence.
            int nxt = adj[cur][adj[cur].size()-1-i];
            if(vis[nxt])    continue;
            s.push(nxt);
        }
    }
}

void dfs2(int cur){
    vis[cur] = true;
    cout << cur << " ";
    for(auto nxt : adj[cur]){
        if(vis[nxt])    continue;
        dfs2(nxt);
    }
}

void bfs(){
    queue<int> q;
    q.push(v);
    vis[v] = true;
    while(!q.empty()){
        int cur = q.front();
        cout << cur << " ";
        q.pop();
        for(auto nxt : adj[cur]){
            if(vis[nxt])   continue;
            q.push(nxt);
            vis[nxt] = true;
        }
    }
}

int main(){
    cin >> n >> m >> v;
    
    while(m--){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i=1; i<=n; i++){
        sort(adj[i].begin(), adj[i].end()); // smaller number first
    }
    dfs2(v); // also work dfs1();
    cout << '\n';
    fill(vis+1, vis+n+1, false); // int i = 1, so +1
    bfs();
    return 0;
}