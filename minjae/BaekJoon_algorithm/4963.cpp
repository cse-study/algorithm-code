#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int arr[55][55];
bool vis[55][55];
int dx[8] = {0,0,1,-1,1,1,-1,-1};
int dy[8] = {1,-1,0,0,1,-1,1,-1};

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int w,h,val;
    while(1){
        cin >> w >> h;
        if(w == 0 && h == 0)    break;
        fill(&arr[0][0], &arr[h+2][w+2], 0);
        fill(&vis[0][0], &vis[h+2][w+2], false);

        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                cin >> arr[i][j];
            }
        }

        int ans=0;
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if(arr[i][j] == 0 || vis[i][j] == true) continue;
                ans++; // 섬갯수 추가
                
                queue<pair<int,int> > Q;
                vis[i][j] = true;
                Q.push(make_pair(i,j));
                while(!Q.empty()){
                    auto cur = Q.front(); Q.pop();
                    for(int dir=0; dir<8; dir++){
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if(nx < 0 || nx>= w || ny <0 || ny >= h)    continue;
                        if(vis[nx][ny] == true || arr[nx][ny] == 0) continue;
                        vis[nx][ny] = 1;
                        Q.push(make_pair(nx,ny));
                        //cout << "push 했다" << "i: " << nx << " j: " << ny << '\n';
                    }
                }
            }
        }
    
        cout << ans << "\n";
        fill(&arr[0][0], &arr[h+2][w+2], 0);
        fill(&vis[0][0], &vis[h+2][w+2], false);
    }
}