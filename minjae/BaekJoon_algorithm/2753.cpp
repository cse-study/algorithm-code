#include <iostream>
using namespace std;


int main() { 

int A;
cin>>A;

if ((A%4 == 0 && A%100 !=0) || A%400 ==0)
    cout << "1";
else{
    cout << "0";
}


return 0;
}
