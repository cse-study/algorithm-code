#include <iostream>
#include <math.h>
using namespace std;
int getk(int x1, int y1, int x2, int y2){
    return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}
int main() {
    int T;
    cin>>T;
    for(int i=0; i<T; i++){
        int x1, y1, r1, x2, y2, r2, k;
        cin >> x1 >> y1>> r1>> x2>> y2>> r2;
        k = getk(x1, y1, x2, y2);
        if(x1==x2 && y1==y2 && r1==r2){
            cout << -1;
        }else if(sqrt(k) > r1+r2){
            cout << 0;
        }else if(sqrt(k) == r1+r2){
            cout << 1;
        }else if(k > (r1-r2)*(r1-r2)){
            cout << 2;
        }else if(k == (r1-r2)*(r1-r2)){
            cout << 1;
        }else{
            cout << 0;
        }
        cout << endl;
    }

    return 0;
}