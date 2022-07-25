#include <iostream>
#include <string>
using namespace std;

int main(void){
    int n;
    int a,b;

    cin >> n;

    for (int i =1; i<n+1; i++){
        cin>> a>>b;
        cout<<"Case #"<<i<<": "<< a << " + " << b << " = " << a+b << '\n';
    }

    return 0;
}