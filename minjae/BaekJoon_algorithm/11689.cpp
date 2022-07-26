#include <iostream>
#define ll long long
using namespace std;


ll euler(ll n){ // pi(n) = n(1 - 1/p1)(1-1/p2)....(1-1/pk) n이 소수일떄, 합성수일때, 소수의 n승일때 모든경우 고려한 식이다.
    double result=n;
    for(size_t i=2; i*i<=n; i++){
        if(n%i == 0){
            while(n%i==0){
                n /= i;
            }
            result *= (1.0 - 1.0/i);
        }
    }
    if(n>1){
            result *= (1.0 - 1.0/n);
    }
    return (ll) result;
}

int main(){
    ll n; // euler pi function
    cin >> n;
    cout << euler(n);
}