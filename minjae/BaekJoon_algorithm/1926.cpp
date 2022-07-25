#include <iostream>
#include <queue>
#define X first
#define Y second
using namespace std; // 정석 bps 풀이

int board[502][502];
bool check[502][502];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m,num=0,max_area=0;
    cin >> n >> m;
    for(size_t i=0; i<n; i++){
        for(size_t j=0; j<m; j++){
            cin >> board[i][j];
        }
    }   
    for(size_t i=0; i<n; i++){
        for(size_t j=0; j<m; j++){
            if(board[i][j] == 0 || check[i][j]) continue; //not colored or already visited
            num++; // drawing num increase
            queue<pair<int,int>> Q;
            check[i][j] = 1; // starting point is visit
            Q.push({i,j});
            int area = 0;
            while(!Q.empty()){
                area++; // 큐에 원소 하나씩 뺼 때 마다 넓이 1증가
                pair<int,int> cur = Q.front();
                Q.pop();
                for(size_t i=0; i<4; i++){
                    int nx = cur.X + dx[i];
                    int ny = cur.Y + dy[i];
                    if(nx <0 || nx >= n || ny<0 || ny >=m)    continue; // above range
                    if(check[nx][ny] || board[nx][ny] != 1)   continue; //already vistied or can't go area
                    check[nx][ny] =1;
                    Q.push({nx,ny});
                }
            }
            max_area = max(max_area,area);
        }
    }
    cout << num << '\n' << max_area;
}