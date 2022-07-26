#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int m,c,n;
    cin >> m >> c >> n;
    int res = m*c - n;
    if (res <=0)    cout << "0";
    else            cout << res; 
}