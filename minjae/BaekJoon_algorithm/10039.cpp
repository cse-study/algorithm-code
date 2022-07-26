#include <iostream>
using namespace std; 

int main(){
    int a,sum=0,n=5;
    while(n--){
        cin >> a;
        if(a<40)    a=40;
        sum +=a;
    }
    cout << sum/5;
}