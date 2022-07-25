#include <iostream>
using namespace std;

int main() 
{ 
    int A;
    int B;
    cin>>A >> B ;

    int a_1 =B/100;
    int a_2 =(B/10)%10;
    int a_3 =B%10;  
    
    cout<< a_3*A << endl;
    cout<< a_2*A << endl;
    cout<< a_1*A << endl;
    cout<< A*B;

    return 0;
}
