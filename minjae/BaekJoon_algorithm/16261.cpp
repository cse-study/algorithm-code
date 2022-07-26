#include <iostream>
using namespace std;

long num, a, b, c, d;

long GCD(long x, long y){
    if (y ==0)  return x;
    else    return GCD(y, x%y);
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> num;
    while(num--){
        cin >> a >> b >> c >> d;
        long lcm_down = b*d/GCD(b,d);
        long up_first = a*lcm_down/b;
        long up_second = c*lcm_down/d;
        long lcm_up = up_first*up_second/GCD(up_first,up_second);
        long gcd = GCD(lcm_up, lcm_down);
        cout << lcm_up/gcd << " " << lcm_down/gcd << '\n';
    }
    return 0;
}