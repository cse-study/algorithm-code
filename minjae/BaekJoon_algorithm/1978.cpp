#include <iostream>
#include <cmath>
using namespace std;

bool prime(int k){
    if (k <= 1)
        return false;
    for (int i=2; i<=sqrt(k); ++i){
        if (k%i ==0){
            return false;
        }
    }
    return true;
}


int main(){
    int n;
    cin >> n;
    int cnt =0;
    for (int i=0; i<n; ++i){
        int t;
        cin >> t;

        if (prime(t) == true){
            cnt++;
        }
    }

    cout << cnt << endl;
    return 0;
}
