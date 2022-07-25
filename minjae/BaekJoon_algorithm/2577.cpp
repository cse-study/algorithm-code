#include <iostream>
using namespace std;

int main(void){
    int a,b,c;
    cin >> a >> b >> c;
    int val;
    int arr[10] = {0};
    val = a*b*c;

    while(val != 0){
        arr[val % 10] = arr[val % 10] +1;
        val /= 10;
    }

    for (int i =0; i<10; i++)
        cout << arr[i] << endl;

return 0;
}