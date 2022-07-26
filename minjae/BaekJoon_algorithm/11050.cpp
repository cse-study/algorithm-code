#include <iostream>
#include <cmath>
#define ll long long
using namespace std;

ll fac(ll n){
    ll r = 1;
    for(ll i=1; i<=n; i++){
        r *= i;
    }
    return r;
}

int main(){
    ll n,k;
    cin >> n >> k;
    ll result = fac(n)/(fac(k)*fac(n-k));
    cout << result;
} // i use fac. but, using dp is more effective