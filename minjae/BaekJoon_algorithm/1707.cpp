#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> adj[200002];
int vis[200002];
int t,n,m;

bool bfs(){
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        vis[i] = -1;
        adj[i].clear();
    }

    while(m--){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int st=1; st<=n; st++){
        if(vis[st] != -1)   continue;
        queue<int> q;
        q.push(st);
        vis[st] = 0;
        while(!q.empty()){
            int cur = q.front(); q.pop();
            for(auto nxt: adj[cur]){
                if(vis[nxt] != -1)  continue;
                vis[nxt] = vis[cur] + 1;
                q.push(nxt); 
            }
        }
    }

    for(int i=1; i<=n; i++){
        for(auto a: adj[i]){
            if((vis[i] - vis[a]) % 2 == 0)  return false; // 홀짝홀짝 하면서 bfs 퍼지는데 두개차가 짝수면 같은녀석임으로 이분그래프 아니다.
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--){
        bool check = bfs();
        if(check == true)    cout << "YES" << '\n';
        else                cout << "NO" << '\n';
    }
    return 0;
}