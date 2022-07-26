#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[1002];
bool vis[1002];

int main(){
    int n,m;
    cin >> n >> m;
    
    while(m--){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int num=0;
    for(int i=1; i<=n; i++){
        if(vis[i])  continue;
        num++;
        queue<int> q;
        q.push(i);
        vis[i] = true;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(auto nxt : adj[cur]){
                if(vis[nxt])    continue;
                q.push(nxt);
                vis[nxt] = true;
            }
        }
    }

    cout << num;
    return 0;
}