#include <iostream>
using namespace std; // using dp (draw 2d array D[101][10001])

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int n,k;
    cin >> n >> k;
    long long D[10001]={0};
    int arr[101]={0};
    for(size_t i=1; i<=n; i++){
        cin >> arr[i];
    }

    D[0]=1;

    for(size_t i=1; i<=n; i++){
        for(size_t j=1; j<=k; j++){
            if(j >= arr[i])
                D[j] = D[j] + D[j-arr[i]]; 
                // if we use 2d array memmory over. so use 1d array
                // cover the original val
        }
    }
    cout << D[k];

}