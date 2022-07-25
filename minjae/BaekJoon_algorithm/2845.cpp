#include <iostream>
using namespace std; 

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    int l,p,n=5,a;
    cin >> l >> p;
    
    while(n--){
        cin >> a;
        cout << a-l*p << " ";
    }
}