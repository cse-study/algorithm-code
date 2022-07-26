#include <iostream>
#include <queue>
#define X first
#define Y second
using namespace std; // 상하좌우, 최소거리 -> BPS

int board[1002][1002];
int dist[1002][1002];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> m >> n;
    queue<pair<int, int>> Q;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 1)
                Q.push({i, j});
            if (board[i][j] == 0)
                dist[i][j] = -1;
        }
    }

    while (!Q.empty())
    {
        pair<int, int> cur = Q.front();
        Q.pop();
        for (size_t i = 0; i < 4; i++)
        {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (dist[nx][ny] >= 0)
                continue;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1; // 하루지나면 토마토 익음
            Q.push({nx, ny});
        }
    }
    int ans = 0;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            if (dist[i][j] == -1)
            {
                cout << -1; //익지 않은곳 = 변하지 않은곳
                return 0;
            }
            ans = max(ans, dist[i][j]);
        }
    }
    cout << ans;
}