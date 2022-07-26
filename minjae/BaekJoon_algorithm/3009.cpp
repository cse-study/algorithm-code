#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){

    int x1,y1, x2,y2, x3,y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    if(x1 == x2)
        cout << x3 << " ";
    if(x2 == x3)
        cout << x1 << " ";
    if(x3 == x1)
        cout << x2 << " ";

    if(y1 == y2)
        cout << y3;
    if(y2 == y3)
        cout << y1;
    if(y3 == y1)
        cout << y2;

}