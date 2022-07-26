#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[502];
int vis[502];

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

    int num = 0;

    queue<int> q;
    q.push(1);
    vis[1] = 0;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(auto nxt : adj[cur]){
            if(vis[nxt] > 0)    continue;
            q.push(nxt);
            vis[nxt] = vis[cur] + 1;
        }
    }
    vis[1] = 0; // can't include 상근 self
    for(int i=1; i<=n; i++){
        if(vis[i] == 1 || vis[i] == 2) num++;
    }

    cout << num;
    return 0;
}