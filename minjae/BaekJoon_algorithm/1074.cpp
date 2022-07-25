#include <bits/stdc++.h>
using namespace std;

int z(int n, int a, int b){
    if(n == 0) return 0;
    
    if (a < pow(2, n - 1) && b < pow(2, n - 1)){
        return z(n-1,a,b);
    }
    if (a < pow(2, n - 1) && b >= pow(2, n - 1)){
        return (pow(2, n - 1) * pow(2, n - 1) + z(n - 1, a, b - pow(2, n - 1)));
    }
    if (a >= pow(2, n - 1) && b < pow(2, n - 1)){
        return (2 * pow(2, n - 1) * pow(2, n - 1) + z(n - 1, a - pow(2, n - 1), b));
    }
    if (a >= pow(2, n - 1) && b >= pow(2, n - 1)){
        return (3 * pow(2, n - 1) * pow(2, n - 1) + z(n - 1, a - pow(2, n - 1), b - pow(2, n - 1)));
    }
}
int main(){
    int n, a, b;
    cin >> n >> a >> b;
    cout << z(n, a, b);
}