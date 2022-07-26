#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int c,m,s,add_s;
    cin >> c >> m >> s;
    cin >> add_s;
    int tot = c*3600 + m *60 + s + add_s;
    s = tot%60;
    tot -= s;
    m = (tot/60)%60;
    tot -= m*60;
    c = (tot/3600)%24;
    cout << c << " " << m << " " << s;
}