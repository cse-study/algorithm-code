#include <iostream>
using namespace std; // using two pointer algorithm

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    long long n,s;
    cin >> n >> s;
    int arr[n];
    for(size_t i=0; i<n; i++){
        cin >> arr[i];
    }

    long long sum=0;
    int lo=0,hi=0,len=hi-lo;
    int l_len = n+10;
    while(1){
        if(sum>=s){
            sum -= arr[lo++];
        } else if(hi == n){
            break;
        } else{
            sum += arr[hi++];
        }
        if(sum >= s){ // if condition fit, then set l_len
            len = hi - lo;
            if (l_len >= len)    l_len = len;
        }
    }
    if (l_len == (n+10) ) cout << "0";
    else    cout << l_len;
}