#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int edge[101][101];
    int reach[101][101];
    int n,val;

    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> val;
            edge[i][j] = val;
        }
    }

    for(int start=0; start<n; start++){ 
        int vis[101]= {0}; // 초기화 안하면 망함!
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            int cur = q.front(); q.pop();
            for(int i=0; i<n; i++){
                if(edge[cur][i] && !vis[i]){ // cur 에서 i로 갈수있고, i 가 아직 방문전이면
                    q.push(i);
                    reach[start][i]=1;
                    vis[i] = true;
                }
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << reach[i][j] << " ";
        }
        cout << '\n';
    }

    
    return 0;
}