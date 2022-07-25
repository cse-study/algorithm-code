#include <iostream>
#include <cmath>
using namespace std;

int GCD(int a, int b){
    if (b == 0) return a;
    else        return GCD(b,a%b);
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int a,b;
    cin >> a >> b; // a*b = gcd * lcd

    int k = a;
    a /= k;
    b /= k;

    int m,n;
    for(int i=sqrt(b); i<=b; i++){ // find min m+n
        if(b%i ==0 && GCD(i,b/i) == 1){ 
            m = i;
            n = b/i;
            break;
        }
    }

    m *= k;
    n *= k;
    cout << min(n,m) << " " << max(n,m);
}