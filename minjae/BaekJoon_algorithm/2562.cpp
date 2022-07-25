#include <iostream>
using namespace std;

int main(){
    int arr[100];
    int pNum=0, Max = 0;

    for (int i = 1; i <=9; i++){
        cin >> arr[i];

        if (Max < arr[i]){
        Max = arr[i];
        pNum = i;
        }
    }
    cout << Max <<" "<< pNum << endl;

    return 0;
}