#include <iostream>
#include <vector>

using namespace std;
#define WEIGHT 0
#define VALUE 1

int item[101][2] = {0,};
int dp[101][100001] = {0,};

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    int n,k;
    cin >> n >> k;
    int weight, value;
    for(int i=1; i<=n; i++){
        cin >> weight >> value;
        item[i][WEIGHT] = weight;
        item[i][VALUE] = value;
    }

    for(int i=1; i<=n; i++){
        dp[0][i] = 0; 
    }

    for(int i=1; i<=n; i++){ // i는 물건 개수 (가로의미)
        for(int j=1; j<=k; j++){ // j는 버티는 무게를 조금씩 올리면서 2차원 dp를 채운다. (세로의미)
            if(item[i][WEIGHT] <= j){ // 버티는 제한무게보다 작은 경우만 고려한다
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-item[i][WEIGHT]] + item[i][VALUE]);
            }
            else{
                dp[i][j] = dp[i-1][j]; // 무게가 큰 경우는, 그냥 위의 경우와 같다.
            }
        }
    }
    cout << dp[n][k];
}