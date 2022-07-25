#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(size_t i=0; i<n; i++){
        int a;
        cin >> a;
        arr[i] = a;
    }
    sort(arr, arr+n);
    cout << arr[0] * arr[n-1] << '\n';
}