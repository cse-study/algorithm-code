#include <iostream>
using namespace std;

long long fun(int a){ // cuz time limit
    long long res=0;
    for(int i=1; i<=a; i++){
        res += (a/i)*i;
    }
    return res;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int a;
    cin >> a;
    cout << fun(a);
}