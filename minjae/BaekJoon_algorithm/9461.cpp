#include <iostream>
using namespace std; // using dp

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n,k;
    long long D[101]={0}; // type is infortant
    D[1] = 1;
    D[2] = 1;
    D[3] = 1;
    D[4] = 2;
    D[5] = 2;

    cin >> n;
    while(n--){
        cin >> k;
        for(size_t i=6; i<=k; i++){
        D[i] = D[i-1] + D[i-5];
        }
        cout << D[k] << '\n';
    }
}