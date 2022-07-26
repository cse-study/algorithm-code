#include <iostream>
using namespace std; //dp로 푼다
//2차원으로 풀이가능 배열을 i까지 올라왔을때 밟지않을 계단의 최솟값 -> 밟은 계단의 최댓값 구함

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,s[301],sum=0;
    int d[301];

    cin >> n;
    for(size_t i=1; i<=n; i++){
        cin >> s[i];
        sum += s[i];
    }
    if(n<=2){
        cout << sum;
        return 0;
    }
    d[1] = s[1];
    d[2] = s[2];
    d[3] = s[3];
    for(size_t i=4; i<n; i++){
        d[i] = min(d[i-2], d[i-3]) +s[i]; // i번째 안밟음 -> 그전꺼는 무조건 밟음. 그럼 2칸전 or 3칸전에를 안밟을수 있음
    }
    cout << sum - min(d[n-1],d[n-2]); // 마지막 계단 밟음 -> 그전 or 그전전꺼 안밟음 -> 전체 - min(그전, 그전전)
}