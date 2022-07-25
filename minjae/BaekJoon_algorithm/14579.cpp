#include <iostream> 
using namespace std;

int fun (int n){
    return n*(n+1)/2;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int a,b;
    cin >> a >> b;
    long long res=1;
    for(int i=a; i<=b; i++){
        int temp = fun(i);
        res = (res*temp)%14579;
    }
    cout << res;
}