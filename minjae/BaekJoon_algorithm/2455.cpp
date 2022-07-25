#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int a1,a2,a3,a4,b1,b2,b3,b4;
    cin >> a1 >> b1;
    cin >> a2 >> b2;
    cin >> a3 >> b3;
    cin >> a4 >> b4;

    cout << max({b1,b1+b2-a2,b1+b2+b3-a2-a3});
}