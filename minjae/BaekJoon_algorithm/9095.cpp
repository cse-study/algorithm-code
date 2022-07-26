#include <iostream>
using namespace std; //dp로 푼다
// arr[5] = 1이 끝에온다(합이 4되야함) + 2가 끝에온다 (합이 3되어야함) + 3이 끝에온다 (합이 2되어야함)
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int arr[11];
    arr[1]=1;
    arr[2]=2;
    arr[3]=4;
    int n,num;
    cin >> n;

    for(size_t i=4; i<=10; i++){
        arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
    }

    while(n--){
        cin >> num;
        cout << arr[num] << '\n';
    }
}