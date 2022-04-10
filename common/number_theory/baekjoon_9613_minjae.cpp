#include <iostream>
using namespace std;

int GCD(int a, int b){ // extended uclid algorithm
    if(b == 0)  return a;
    else    return GCD(b, a%b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int n,k;
    cin >> n;
    while(n--){
        cin >> k;
        int arr[k];
        long sum=0;
        for(size_t i=0; i<k; i++){
            cin >> arr[i];
        }
        for(size_t i=1; i<k; i++){
            for(size_t j=0; j<i; j++){
                sum += GCD(arr[j],arr[i]);
            }
        }
        cout << sum << '\n';
    }
}