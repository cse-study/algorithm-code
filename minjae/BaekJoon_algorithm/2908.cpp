#include <iostream>
#include <string>
using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;

    string big;
    for (int i =2; i>0; --i){
        if (a[i] > b[i]){
            big = a;
            break;
        }
        if (a[i] < b[i]){
            big = b;
            break;
        }                    
    }
    cout << big[2] << big[1] << big[0] << endl;
    return 0;
}
