#include <iostream>
using namespace std; //dp로 간단하게 푼다

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int arr[1000001];
    arr[1]=0;
    int n;
    cin >> n;
    for(size_t i =2; i<=n; i++){
        arr[i]= arr[i-1]+1;
        if(i%2 == 0)
            arr[i] = min(arr[i], arr[i/2]+1);
        if(i%3 == 0)
            arr[i] = min(arr[i], arr[i/3]+1);
    }
    cout << arr[n];
}