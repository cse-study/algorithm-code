#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> adj[5002];
int vis[5002];
int n,m;

int bfs(int st){
    queue<int> q;
    q.push(st);
    vis[st] = 0;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(auto nxt : adj[cur]){
            if(vis[nxt] >= 0)   continue;
            q.push(nxt);
            vis[nxt] = vis[cur] + 1;
        }
    }
    int res=0;
    for(int i=1; i<=n; i++){
        res += vis[i];
    }
    return res;
}

int main(){
    cin >> n >> m;
    while(m--){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    int store[n+1];
    int min_val = 1000000000;
    for(int i=1; i<=n; i++){
        fill(vis, vis+n+1, -1);
        store[i] = bfs(i);
        min_val = min(min_val, bfs(i));
    }
    
    for(int i=1; i<=n; i++){
        if(store[i] == min_val) {
            cout << i;
            break;
        }
    }
    return 0;
}