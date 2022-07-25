#include <iostream>
#include <queue>
using namespace std;

int board[305][305];
bool check[305][305];
int dist[305][305];
int dx[8] = {2,2,1,1,-1,-1,-2,-2};
int dy[8] = {1,-1,2,-2,2,-2,1,-1};
int test,I,a_s,b_s,a_e,b_e;


int main(){
    cin >> test;
    while(test--){
        cin >> I;
        cin >> a_s >> b_s;
        cin >> a_e >> b_e;
        if(a_s == a_e && b_s == b_e){
            cout << 0 << '\n';
            continue;
        }

        for(int i=0; i<I; i++){
            fill(dist[i], dist[i]+I, 0);
            fill(check[i], check[i]+I, false);

        }

        queue<pair<int,int> > Q;
        dist[a_s][b_s] = 0;
        check[a_s][b_s] = true;
        Q.push(make_pair(a_s,b_s));
        while(!Q.empty()){
            pair <int,int> cur = Q.front();
            Q.pop();
            for(int i=0; i<8; i++){
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];
                if(nx < 0 || nx >= I || ny < 0 || ny >= I)      continue;
                if(check[nx][ny] == true || dist[nx][ny] > 0)   continue;
                check[nx][ny] = true;
                dist[nx][ny] = dist[cur.first][cur.second] + 1;
                Q.push(make_pair(nx,ny));
            }
        }
        cout << dist[a_e][b_e] << '\n';
    }
    return 0;
}