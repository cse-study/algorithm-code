#include <iostream> // lcd = ab/gce
using namespace std;

int gcd(long long a, long long b){
    if (b == 0)
        return a;
    else{
        return gcd(b, a % b);
    }
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    long long a, b;
    cin >> a >> b;
    int r = gcd(a, b);

    cout << a*b/r;
}