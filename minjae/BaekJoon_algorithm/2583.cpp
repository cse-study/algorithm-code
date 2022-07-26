#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
bool vis[105][105];
int board[105][105];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
 int m,n,k;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    cin >> m >> n >> k;
    int ax,ay,bx,by;
    while(k--){
        cin >> ax >> ay >> bx >> by;
        for(int i= ax; i<bx; i++){
            for(int j = ay; j < by; j++){
                board[j][i] = 1; // 받아서 도형 맞는지 x,y 확인해야함! 실수 종종한다 나..
            }
        }
    }

    int count=0;
    vector<int> areaV;
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(board[i][j] == 1 || vis[i][j] == 1)  continue; // 도형이 있거나, 이미 방분했다면 넘어감
            queue<pair<int,int> > Q;
            vis[i][j]=1; // 시작할것이니 이지점은 방문했다 체크
            Q.push(make_pair(i,j));
            count++;
            int area = 1;
            while(!Q.empty()){
                auto cur = Q.front(); Q.pop();
                for(int dir=0; dir<4; dir++){
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    if(nx <0 || nx >= m || ny <0 || ny >=n) continue;
                    if(board[nx][ny] == 1 || vis[nx][ny] == 1)  continue;
                    vis[nx][ny]=1;
                    Q.push(make_pair(nx,ny));
                    area++; // 추가해야 증가한다. 위치 실수 주의!
                }
            }
            areaV.push_back(area);
        }
    }
    cout << count << '\n'; 
    sort(areaV.begin(), areaV.end());
    for(auto i : areaV) cout << i << " ";
}