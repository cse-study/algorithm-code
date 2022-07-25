#include <iostream>
using namespace std; 

int main(){
    int a,b,c,d,e,sum=0;
    cin >> a >> b >> c >> d >> e;
    
    sum = (a*a)+(b*b)+(c*c)+(d*d)+(e*e);
    cout << sum%10;
}