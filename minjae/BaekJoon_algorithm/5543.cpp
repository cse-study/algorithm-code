#include <iostream>
using namespace std; 

int main(){
    int a,b,c,d,e,min_ham=0,min_col=0;
    cin >> a >> b >> c >> d >> e;
    
    min_ham = min(a,b);
    min_ham = min(min_ham,c);
    min_col = min(d,e);
    
    cout << min_ham + min_col - 50;
}