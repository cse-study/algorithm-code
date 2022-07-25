#include <iostream>
using namespace std; 

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    int a,b,t;
    cin >> a >> b;
    cin >> t;

    if(b+t>=60){
        int resi = (b+t)/60; // resi = 몇시간 초과
        cout << (a + resi)%24 << " " << b+t - 60*resi; // %24 -> 23시가 최대
    }
        
    else
        cout << a << " " << b+t;
}