#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int a,b,c,res;
    cin >> a >> b >> c;
    if(a == b && b == c)    res = 10000 + a * 1000;
    else if ( a != b && b !=c && a!=c)  res = max({a,b,c}) * 100;
    else if(a == b && b!=c)             res = 1000 + a * 100;
    else if (a == c && a!=b)            res = 1000 + a * 100;
    else if (b == c && a!=b)            res = 1000 + b * 100;

    cout << res;
}