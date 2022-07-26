#include <iostream>
using namespace std; // using dp

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int D[100001];
    fill(D,D+100001,-1);
    D[0] = 0;
    D[2] = 1;
    D[4] = 2;
    D[5] = 1;
    for(size_t i=6; i<=n; i++){
        if(i%5==0) // 바로 5로 나누어 지는경우,
            D[i] = i/5;
        for(size_t j=i/5; j>0; j--){ // 5를 최대한 많이뺴고, 2로 채울수있는 경우
            if ((i-5*j)%2 == 0)
                D[i] = max(D[i], D[i-5*j]+D[5*j]);
        }
        if(D[i] == -1 && i%2 == 0){ // 아직 위에서 변경하지 않았고, 2로 나눠지면 2로나눔
            D[i] = i/2;
        }
    }
    cout << D[n];
}