#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[102];
bool vis[102];

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
    vis[1] = true;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(auto nxt : adj[cur]){
            if(vis[nxt])    continue;
            num++;
            q.push(nxt);
            vis[nxt] = true;
        }
    }

    cout << num;
    return 0;
}