#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    long n,m;
    cin >> n >> m;
    cout << abs(n-m);
}