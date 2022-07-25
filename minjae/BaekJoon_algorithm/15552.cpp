#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int n;
    int a,b;

    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;

    for (int i=0; i<n; i++)
    {
        cin >> a>>b;
        cout << a+b<< '\n';
    }

return 0;
}