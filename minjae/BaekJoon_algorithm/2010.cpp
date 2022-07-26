#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int n,k,sum=0;
    cin >> n;
    int ori = n;
    while(n--){
        cin >> k;
        sum += k;
    }
    cout << sum + 1 - ori;
}