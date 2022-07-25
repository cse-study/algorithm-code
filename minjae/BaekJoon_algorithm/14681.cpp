#include <iostream>
using namespace std;


int main() { 

int A;
int B;
cin>>A >>B;

if (A>0 && B>0)
    cout << "1";

else if (A<0 && B>0)
    cout << "2";

else if (A<0 && B<0)
    cout << "3";

else if (A>0 && B<0)
    cout <<"4";

return 0;
}
