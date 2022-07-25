#include <iostream>
using namespace std;

int main(void){
    int arr[42] = {0};
    int n;
    int sum=0;
    for (int i = 0; i<10; i++){
        cin >> n;
        arr[n%42] =1;
    }

    for(int i = 0; i<42; i++){
        sum = sum + arr[i];
    }

    cout << sum;
    
return 0;
}