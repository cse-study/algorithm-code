#include <iostream>
#include <algorithm>
using namespace std;

#define X first
#define Y second

int n, a, b;
pair<int, int> p[100004];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> p[i].Y >> p[i].X;
  }
  sort(p, p + n);
  for(int i = 0; i < n; i++) cout << p[i].Y << ' ' << p[i].X << '\n';
}