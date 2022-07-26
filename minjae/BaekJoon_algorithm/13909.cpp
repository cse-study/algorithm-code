#include <iostream>
using namespace std;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    long n;
    cin >> n;
    int cnt=0;
    for(size_t i=1; i*i <=n; i++)   cnt++; 
    // this problem mean square number, cuz n^2's divisor 1,n,n^2 -> open, close, open
    cout << cnt;
}