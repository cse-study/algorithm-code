#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[102000];
int vis[102000]; // distance

int main(){
    int n,k,m;
    cin >> n >> k >> m;
    
    for(int i=1; i<=m; i++){
        for(int j=1; j<=k; j++){
            int a;
            cin >> a;
            adj[n+i].push_back(a); // n+i 번째 vertex = i 번째 하이퍼튜브의 정점
            adj[a].push_back(n+i); // no directed graph
            /* 처음 문제의 예시로 보면, adj[1~9] 까지는 10~14값들이 저장, adj[10~14]에는 1~9까지 값들이 저장.
             왜 정점을 n+m개를 두냐면, n개만 뒀을경우 하이퍼 즉 한방에 여러정점을 갈수있는 bfs를 돌리기 힘들지만,
             n+m개를 두면, n에서 m으로 갔다가, m에서 n으로 가면 한번에 여러vertex를 가는것을 표현가능하다.
             이해가 안되면 실제로 이알고리즘을 따라, 예시를 따라 adj 원소들을 그리면서 해보면 이해할수 있다 */
        }
    }

    fill(vis, vis+n+m+1, -1); // 정점을 n+m개로 잡았으니 n+m+1로 초기화 시켜준다.
    queue<int> q;
    q.push(1);
    vis[1] = 0;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(auto nxt : adj[cur]){
            if(vis[nxt] >= 0)  continue;
            q.push(nxt);
            vis[nxt] = vis[cur] + 1;
        }
    }
    
    if(vis[n] == -1)    cout << vis[n];
    else cout << vis[n]/2 + 1; //왔다 갔다 하는것이니 n지점(1~n) 의 vis 값은 항상 짝수이다.
    return 0;
}

/*
한 하이퍼튜브에 연결된 역들에 대해 전부 서로 간선을 연결할 수는 없다.
대신 각 하이퍼튜브 자체를 정점으로 생각해 그래프를 만들고 거기서 BFS를
진행하면 된다. 
*/