#include <iostream>
#include <algorithm>
using namespace std; // using intuitive

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, cnt = 0;
	cin >> n;
	while (n > 0) {
		if (n % 5 == 0) {
			cout << n / 5 + cnt;
			return 0;
		}
		cnt++;
		n -= 2;
	}
	cout << "-1";
	return 0;
}