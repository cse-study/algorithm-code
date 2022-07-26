#include <iostream>
using namespace std;

int main(){
    int a,b;
    cin >> a >> b;
    
    int gcd =0;
    for(size_t i=1; i<=a; i++){
        if(a%i == 0 && b%i == 0){
            gcd = i;
        }
    }
    cout << gcd << '\n' << a*b/gcd;

}