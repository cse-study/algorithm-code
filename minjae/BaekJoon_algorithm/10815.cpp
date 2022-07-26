#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int n,m,k;
    cin >> n;
    long arr_S[n];
    
    for(size_t i=0; i<n; i++){
        cin >> arr_S[i];
    }
    cin >> m;
    long arr_C[m];
    bool res[m];
    for(size_t i=0; i<m; i++){
        cin >> arr_C[i];
    }

    sort(arr_S, arr_S +n);

    for(size_t i=0; i<m; i++){ // using binary search
        int right = n-1;
        int left = 0;
        while(left <= right){
            int mid = (right+left)/2;
            if(arr_S[mid] == arr_C[i]){
                res[i]=1;
                break;
            }
            if(arr_S[mid] > arr_C[i]){
                right = mid-1;
            }
            else{
                left = mid + 1;
            }
        }
    }
    for(size_t i=0; i<m; i++){
        if(res[i] == 1) cout << "1" <<" ";
        else cout << "0" << " ";
    }
}