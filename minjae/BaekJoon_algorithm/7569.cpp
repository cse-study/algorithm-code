#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std; 

int board[105][105][105];
int dist[105][105][105];
int dx[6] = {1,-1,0,0,0,0};
int dy[6] = {0,0,1,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m,l;
    cin >> m >> n >> l;
    queue<pair< pair<int,int>, int> > Q;
    for(size_t k=0; k<l; k++){
        for(size_t i=0; i<n; i++){
            for(size_t j=0; j<m; j++){
                cin >> board[i][j][k];
                if(board[i][j][k] == 1)
                    Q.push(make_pair(make_pair(i,j),k));
                if(board[i][j][k] == 0)
                    dist[i][j][k] = -1;
            }
        }
    }

    
    while(!Q.empty()){
        pair<pair<int,int>, int> cur = Q.front();
        Q.pop();
        for(size_t i=0; i<6; i++){
            int nx = cur.first.first + dx[i];
            int ny = cur.first.second+ dy[i];
            int nz = cur.second + dz[i];
            if(nx<0 || nx>=n || ny<0 || ny>=m || nz<0 || nz>=l)  continue;
            if(dist[nx][ny][nz]>=0) continue; 
            dist[nx][ny][nz] = dist[cur.first.first][cur.first.second][cur.second]+1;
            Q.push(make_pair(make_pair(nx,ny),nz));
        }
    }
    int ans = 0;
    for(size_t k=0; k<l; k++){
        for(size_t i=0; i<n; i++){
            for(size_t j=0; j<m; j++){
                if(dist[i][j][k] == -1){ 
                    cout << -1; 
                    return 0; 
                }
                ans = max(ans, dist[i][j][k]);
                
            }
        }
    }
    cout << ans;
}