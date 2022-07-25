#include <iostream>
using namespace std;

long long D[101][10]; //D[i][j] = 길이가 i면서 j로 시작하는 경우의수 (main 밖에 둬야함...)

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    long long res=0;
    cin >> n;

    for(size_t i=1; i<=9; i++)  
        D[1][i] = 1;
    
    for(size_t i=2; i<=n; i++){
        for(size_t k=0; k<=9; k++){
            if(k !=0) D[i][k] += D[i-1][k-1];
            if(k !=9) D[i][k] += D[i-1][k+1];
            D[i][k] %= 1000000000;
        }
    }

    for(size_t i=0; i<=9; i++){
        res += D[n][i];
    }
    res %= 1000000000;
    cout << res;
}