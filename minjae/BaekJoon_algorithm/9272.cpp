#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // all the gcd(m1,m2) is 1 so compute combination tempC2

    int a, b;
    cin >> a >> b;
    int temp = b - a + 1;
    cout << (temp * (temp - 1)) / 2;
}