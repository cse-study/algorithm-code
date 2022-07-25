#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[102];
bool vis[102];
int num = 0;

void dfs(int cur){
    vis[cur] = true;
    for(auto nxt : adj[cur]){
        if(vis[nxt])    continue;
        num++;
        dfs(nxt);
    }
}

int main(){
    int n,m;
    cin >> n;
    cin >> m;
    
    while(m--){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    
    dfs(1);

    cout << num;
    return 0;
}