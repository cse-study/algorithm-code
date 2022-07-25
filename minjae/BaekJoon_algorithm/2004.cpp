#include <iostream>
#include <vector>
#define ll long long
using namespace std; 

// 조합식에서 n!/n-k!*k! -> 2,5를 몇개가지고 있는지 판별 각 숫자로 나눠주면서 count 한

ll count_two(ll n){
    ll c =0;
    while(n){
        n /=2;
        c += n;
    }
    return c;
}

ll count_five(ll n){
    ll c =0;
    while(n){
        n /=5;
        c += n;
    }
    return c;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    ll n,m;
    cin >> n >> m;
    cout << min(count_two(n) - count_two(m) - count_two(n-m),count_five(n) - count_five(m) - count_five(n-m));
    
}