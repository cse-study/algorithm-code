#include <iostream>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;

    int x, y;
    x = c / b;
    y = c % b;

    cout << x << " " << y;
}