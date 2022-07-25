#include <iostream>
using namespace std;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int a, b, c, d, sum=0;
    cin >> a >> b >> c >> d;
    sum = a+b+c+d;
    cout << sum/60 << '\n';
    cout << sum%60;
}