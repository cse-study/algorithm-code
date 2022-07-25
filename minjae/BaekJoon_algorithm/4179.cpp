#include <iostream>
#include <queue>
#include <utility>
using namespace std;


string board[1002];
int dist_f[1002][1002]; // fire
int dist_j[1002][1002]; // jihun
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){
    int m,n;
    cin >> n >> m;

    for(int i=0; i<n; i++){
        cin >> board[i];
    }
    for(int i=0; i<n; i++){
        fill(dist_f[i],dist_f[i]+m,-1); // set the all distance -1
        fill(dist_j[i],dist_j[i]+m,-1);
    }

    queue< pair<int,int> > Q1;
    queue< pair<int,int> > Q2;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j] == 'F'){
                Q1.push(make_pair(i,j));
                dist_f[i][j] = 0;
            }
            if(board[i][j] == 'J'){
                Q2.push(make_pair(i,j));
                dist_j[i][j] = 0;
            }
        }
    }

    while(!Q1.empty()){
        pair<int,int> cur_f = Q1.front();
        Q1.pop();
        for(int i=0; i<4; i++){
            int nx = cur_f.first + dx[i];
            int ny = cur_f.second + dy[i];
            if( nx < 0 || nx >= n || ny < 0 || ny >= m)         continue;
            if(dist_f[nx][ny] >= 0 ||  board[nx][ny] == '#')    continue;
            dist_f[nx][ny] = dist_f[cur_f.first][cur_f.second] + 1;
            Q1.push(make_pair(nx,ny));
        }
    }

    while(!Q2.empty()){
        pair<int,int> cur_j = Q2.front();
        Q2.pop();
        for(int i=0; i<4; i++){
            int nx = cur_j.first + dx[i];
            int ny = cur_j.second + dy[i];
            if( nx < 0 || nx >= n || ny < 0 || ny >= m){
                cout << dist_j[cur_j.first][cur_j.second] + 1 << '\n';
                return 0;
            }
            if( dist_j[nx][ny] >= 0 || board[nx][ny] == '#')        continue;
            if( dist_f[nx][ny] <= dist_j[cur_j.first][cur_j.second] + 1 && dist_f[nx][ny] != -1)    continue; // consider fire
            dist_j[nx][ny] = dist_j[cur_j.first][cur_j.second] + 1;
            Q2.push(make_pair(nx,ny));
        }
    }

    cout << "IMPOSSIBLE" << '\n';
    return 0;
}