#include <iostream>
#include <algorithm>
using namespace std; 

void inverse(int s, int e, int *arr){ // 포인터로 변경사항 유지
    reverse(arr+s,arr+e+1);
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    int arr[21];
    for(size_t i=1; i<=20; i++)
        arr[i] = i;
    
    int a=10,s,e;
    while(a--){
        cin >> s >>e;
        inverse(s,e, arr);
    }
    
    for(size_t i=1; i<=20; i++)
        cout << arr[i] << " ";
}