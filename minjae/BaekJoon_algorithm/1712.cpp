#include <iostream>
using namespace std;

int main(){
    int a,b,c;
    cin >> a >> b >> c;

    if(b ==c){
        cout << "-1" << endl;
        return 0;
    }
    double x;
    x = (double)a/(c-b);

    if (x <0){
        cout << "-1" << endl;
    }

    if (x >= 0){
        cout << (int)x+1 << endl;
    }

}
