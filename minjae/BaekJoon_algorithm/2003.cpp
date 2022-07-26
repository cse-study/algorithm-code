#include <iostream>
using namespace std; // using two pointer algorithm

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int n,m;
    cin >> n >> m;
    int arr[n];
    for(size_t i=0; i<n; i++){
        cin >> arr[i];
    }

    int cnt=0,sum=0,lo=0,hi=0;
    while(1){
        if(sum>=m){
            sum -= arr[lo++];
        } else if(hi == n){
            break;
        } else{ // sum < m && hi !=n
            sum += arr[hi++];
        }
        if(sum == m)    cnt++;
    }
    cout << cnt;
}