#include <iostream>
#define ll long long int
using namespace std;


ll get_pow(ll a, ll p, ll mod){
    if(p == 1)  return a%mod;
    ll temp = get_pow(a,p/2,mod)%mod;
    if(p%2 ==1) return (a*((temp*temp)%mod))%mod;
    else        return (temp*temp)%mod;
}

void fun(ll a, ll p){
    if (get_pow(a,p,p) == a)  cout << "yes" << '\n';
    else                    cout << "no" << '\n';
}

bool test(ll n){
    if(n < 2)   return false;
    for(int i=2; i*i<=n; i++){
        if(n%i == 0)    return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    ll p,a;
    while(1){
        cin >> p >> a;
        if(a == 0 && p == 0)    break;
        if(test(p) == true) cout << "no" << '\n';
        else                fun(a,p);
    }
}