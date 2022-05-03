#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
// 뱀의 머리와 꼬리 관리 - 큐 또는 덱으로 구현

int board[101][101];
int dx[4] = {1,0,-1,0}; // 이거 설정 완전 중요
int dy[4] = {0,1,0,-1};
bool exist[101][101]; // 뱀몸통 있나?
char turn[10001]; // 방향전환 위해서

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    int n,k; cin >> n >> k;
    int x,y;
    for(int i=0; i<k; i++){
        cin >> x >> y;
        board[x][y] = 1;
    }
    int l; cin >> l;
    int t; char c;
    for(int i=0; i<l; i++){
        cin >> t >> c;
        turn[t] = c; // 언제 어디로 턴하는지 저장
    }

    queue<pair<int,int> > snake; // 뱀의 몸통위치
    snake.push(make_pair(1,1));
    exist[1][1] = true;

    int ans = 0; //시간
    int now_dir = 0;

    while(1){
        ans++;
        int n_c = snake.back().first + dy[now_dir];
        int n_r = snake.back().second + dx[now_dir];

        if(n_c < 1 || n_c > n || n_r < 1 || n_r > n)    break;
        snake.push(make_pair(n_c, n_r));

        if(turn[ans] == 'D'){
            now_dir +=1;
            if(now_dir == 4)    now_dir =0;
        }
        else if(turn[ans] == 'L'){
            now_dir -= 1;
            if(now_dir == -1)    now_dir =3;
        }

        if(board[n_c][n_r] == 1)    board[n_c][n_r] = 0; // 사과있으면 사과만 제거
        
        else{ // 사과없으면 꼬리 없어짐
            if(exist[n_c][n_r] == true)  break; // 머리가 꼬리에 부딪히면 끝
            exist[snake.front().first][snake.front().second] = false;
            snake.pop();
        }

        if(exist[n_c][n_r] == true) break; // 뱀의 머리와 몸통이 부딪힐경우
        else{
            exist[n_c][n_r] = true; // 그게아니라면 뱀 머리를 true
        }
    }
    cout << ans << '\n';

}