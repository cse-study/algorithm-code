#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int n,sum=0;
    cin >> n;
    for(size_t i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr,arr+n);
    
    for(size_t i=0; i<n; i++){
        sum += arr[i] * (n-i);
    }
    cout << sum;
}