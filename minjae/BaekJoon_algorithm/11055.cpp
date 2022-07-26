#include <iostream>
#include <algorithm>
using namespace std; // using dp

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, arr[1003] = {0}, D[1003] = {0};
    cin >> n;
    
    for(size_t i=1; i<=n; i++){
        cin >> arr[i];
        D[i] = arr[i];
    }
    D[1] = arr[1];
    for(size_t i=2; i<=n; i++){
        for(size_t j=1; j<i; j++){
            if(arr[j] < arr[i])   
                D[i] = max(D[i], D[j] + arr[i]);
        }
    }
    cout << *max_element(D, D+n+1); // 1,100,2 => answer is not 3, 100
}