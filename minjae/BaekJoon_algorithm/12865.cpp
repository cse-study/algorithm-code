#include <iostream>
#include <algorithm>
using namespace std; // using dp, this problem called 01 KnapSack

    int n,k;
    int item[102][2]={0,}, D[102][1000001]={0,};
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> k;
    
    for(size_t i=1; i<=n; i++){
        cin >> item[i][0] >> item[i][1]; // [i][0] = weight, [i][1] = worth
    }

    for(size_t i=1; i<=n; i++){ // i is number of item
        // not get : D[i][j] = D[i-1][j];
        // get : D[i][j] = D[i][j - item_weight] + item_worth
        for(size_t j=0; j<=k; j++){ // j is max weight of item
            if(j<item[i][0])    D[i][j] = D[i-1][j]; // can't get
            else D[i][j] = max(D[i-1][j], D[i-1][j-item[i][0]]+item[i][1]);
        }
    }
    
    cout << D[n][k];
}