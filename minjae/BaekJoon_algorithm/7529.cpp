#include <iostream>
using namespace std; //dp로 푼다
// 1차원 배열로 풀면 3계단 연속 제약이 생겨서 점화식 못세움. 그래서 2차열배열 사용
// D[i][j] = 지금까지 j계단을 연속해서 밟고 i계단까지 밟았을때 점수최댓값, i번쨰는 반드시 밟음
//D[k][1] = k-1안밟음, k-2무조건 밟음

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,s[301];
    int d[305][3];

    cin >> n;
    for(size_t i=1; i<=n; i++){
        cin >> s[i];
    }
    if(n==1){
        cout << s[1];
        return 0;
    }
    
    d[1][1] = s[1];
    d[1][2] = 0;
    d[2][1] = s[2];
    d[2][2] = s[1] + s[2];
    for(size_t i=3; i<=n; i++){
        d[i][1] = max(d[i-2][1], d[i-2][2]) + s[i]; // 지금이 첫번쨰 밟은칸이면 더블점프임으로 2칸전에서의 최댓값 + 현재칸
        d[i][2] = d[i-1][1] + s[i]; //지금이 2번밟았으면 이전칸 + 현재칸
    }
    cout << max(d[n][1],d[n][2]);

}