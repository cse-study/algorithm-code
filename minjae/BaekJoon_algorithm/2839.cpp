#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int a = n/5;
    int b;
    while (1)
    {
        if (a < 0){
            cout << "-1" << endl;
            return 0;
        }

        else if ((n - 5*a)%3==0)
        {
            b = (n-5*a)/3;
            break;
        }

        else{
            a = a-1;
        }
    }
    cout << a+b;
    return 0;
}