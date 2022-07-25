#include <iostream>
#include <cmath>
using namespace std;

bool prime(long long n){
    if(n<2) return false;
    for(size_t i=2; i<=sqrt(n); i++){
        if(n%i ==0) return false;
    }
    return true;
}

void fun(long long n){
    for(long long i=2; i<=n/2; i++){
        if(prime(i)==true && prime(n-i)==true){ // 둘다 소수인지 확인 참이면 출력후 break
            cout << n << " = " << i << " + " << n-i << '\n';
            break;
        }
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    long long n;
    while(1){
        cin >> n;
        if(n == 0)  break;
        fun(n);
    }
}