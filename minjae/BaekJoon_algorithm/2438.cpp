#include <iostream>
using namespace std;

int main(void)
{
    int n;
    cin >> n;

    for(int i =1; i<n+1; i++){
        for(int j=1; j<i+1; j++){
            cout<< "*";
        }
        cout << "\n";
    }

    return 0;
}