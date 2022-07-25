#include <iostream>
using namespace std;

int main(){
    int a,b;
    cin >> a >> b;

    int arr[a];
    for(size_t i = 0; i<a; i++){
        cin >> arr[i];
    }

    for(size_t i=0; i<a; i++){
        if(arr[i] < b){
            cout << arr[i] << " ";
        }
    }

    return 0;
}