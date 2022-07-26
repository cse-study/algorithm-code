#include <iostream>
using namespace std;

int cal(int a){
    int sum = a;
    while(1){
        if(a == 0)  break;
        sum += a%10;
        a /= 10;
    }
    return sum;
}


int main(){
    int arr[20000] = {0,};
    for(size_t i=1; i<10000; i++){
        arr[cal(i)] = 1;
    }

    for(size_t i=1; i<10000; i++){
        if(arr[i]==0)   cout << i << '\n';
    }

    return 0;
}