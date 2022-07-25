#include <iostream>
using namespace std;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int ax,ay,az,cx,cy,cz;
    cin >> ax >> ay >> az;
    cin >> cx >> cy >> cz;
    cout << cx-az << " " << cy/ay << " " << cz-ax;
}