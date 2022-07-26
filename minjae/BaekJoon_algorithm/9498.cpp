#include <iostream>
using namespace std;

int main() { 
    int A;
    cin>>A;

    if (A<=100 && A>=90)        cout<< "A"; 
    else if (A<=89 && A>=80)    cout<< "B"; 
    else if (A<=79 && A>=70)    cout<< "C"; 
    else if (A<=69 && A>=60)    cout<< "D"; 
    else                        cout << "F";
}
