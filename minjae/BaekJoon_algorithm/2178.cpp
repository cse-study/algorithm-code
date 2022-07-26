#include <iostream>
#include <queue>
#define X first
#define Y second
using namespace std; // 정석 bps 풀이

string board[102];
int dist[102][102];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    for(size_t i=0; i<n; i++){
        cin >> board[i];
    }   

    for(size_t i=0; i<n; i++){
        fill(dist[i],dist[i]+m,-1);
    }

    queue<pair<int,int>> Q;
    Q.push({0,0});
    dist[0][0]=0;

    while(!Q.empty()){
        pair<int,int> cur = Q.front();
        Q.pop();

        for(size_t dir=0; dir<4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
            if(dist[nx][ny] >=0 || board[nx][ny] != '1') continue;
            dist[nx][ny] = dist[cur.X][cur.Y]+1; // 한칸씩 이동할때마다 이동거리 1 증가
            Q.push({nx,ny});
        }
    }
    cout << dist[n-1][m-1]+1;
}