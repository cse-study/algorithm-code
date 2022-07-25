#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[10];
bool vis[10];
int dist[10];

void bfs(){
    queue<int> q;
    vis[1] = true;
    q.push(1);
    dist[1]=0;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        cout << cur << " ";
        for(auto nxt : adj[cur]){
            if(vis[nxt])    continue;
            if(dist[nxt] != -1) continue;
            q.push(nxt);
            vis[nxt] = true;
        }
    }
}


int main(){

    return 0;
}