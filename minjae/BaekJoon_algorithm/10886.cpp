#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int n,k, cute=0,ncute=0;
    cin >> n;
    while(n--){
        cin >> k;
        if(k == 0)    ncute++;
        else            cute++;
    }
    if (cute >ncute)    cout << "Junhee is cute!" << '\n';
    else                cout << "Junhee is not cute!" << '\n';
}