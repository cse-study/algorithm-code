#include <iostream>
using namespace std; // using dp

int n;
long long D[1010][10] = {0};
long long sum[1010] = {0};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i=0; i<10; i++){
        D[1][i]=1;
    }
    sum[1]=10;
    
    for(int i=2; i<=n; i++){
        D[i][9] = 1; // 9, 99, 999 is only one case
        
        for(int k=8; k>=0; k--){
            D[i][k] = (D[i-1][k] + D[i][k+1])%10007; 
            // if k is increase, recurrence relation is a-b, and a is %10007 is less than b, so val is - occur wrong val
        }
        for(int j=0; j<10; j++){
            sum[i]+=D[i][j];
        }
    } 
    cout << sum[n]%10007;
}