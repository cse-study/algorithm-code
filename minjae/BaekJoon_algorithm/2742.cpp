#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int n;
    cin >>n;

    for(int i = 1; i<n+1; i++){
        cout << n+1-i << '\n';
    }

    return 0;
}