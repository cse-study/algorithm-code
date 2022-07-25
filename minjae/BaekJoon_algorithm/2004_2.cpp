#include <iostream>
#include <vector>
#define ll long long
using namespace std; 

// 조합식에서 n!/n-k!*k! -> 2,5를 몇개가지고 있는지 판별 각 숫자로 나눠주면서 count 한

pair<ll, ll> count_two(ll n){
    ll c_two =0, c_five =0;
    ll temp = n;
    while(n){
        n /=2;
        c_two += n;
    }
    while(temp){
        temp /=5;
        c_five += temp;
    }
    return {c_two, c_five};
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<pair<ll,ll>> V(3);

    ll n,m;
    cin >> n >> m;
    V[0] = count_two(n);
    V[1] = count_two(m);
    V[2] = count_two(n-m);

    int two = V[0].first - V[1].first - V[2].first;
    int five = V[0].second - V[1].second - V[2].second;
    cout << min(two, five);
}