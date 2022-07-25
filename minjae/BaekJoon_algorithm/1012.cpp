#include <iostream>
#include <queue>
using namespace std;

int board[52][52];
bool check[52][52];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int test,n,m,k;

void bps(int i, int j){
    queue<pair <int,int> > Q;
    Q.push(make_pair(i,j));
    while(!Q.empty()){
        pair<int,int> cur = Q.front();
        Q.pop();
        for(int i=0; i<4; i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx <0 || nx >= n || ny < 0 || ny >= m)       continue;
            if(board[nx][ny] == 0 || check[nx][ny] == 1)    continue;
            check[nx][ny] = 1;
            Q.push(make_pair(nx,ny));
        }
    }
}

int main(){
    cin >> test;
    while(test--){
        cin >> n >> m >> k;
        for(int i=0; i<k; i++){
            int a,b;
            cin >> a >> b;
            board[a][b] =1;
        }
        int count = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == 1 && check[i][j] == 0){
                    bps(i,j);
                    count++;
                }
            }
        }
        cout << count << '\n';
        for(int i=0; i<n; i++){
            fill(board[i],board[i]+m,0);
            fill(check[i],check[i]+m,0);
        }
    }
}