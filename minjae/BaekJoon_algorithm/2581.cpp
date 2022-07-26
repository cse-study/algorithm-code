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
    int a,b;
    int sum=0;
    int cnt =0;
    cin >> a>> b;
    int min = b;
    for (int i=a; i<=b; i++){
        if (prime(i) == true){
            sum = sum+ i;
            cnt += 1;
            if (min >= i){
                min = i;
            }
        }
    }

    if (cnt == 0){
        cout << "-1" << endl;
        return 0;
    }

    cout << sum << endl;
    cout << min << endl;

    return 0;
}
