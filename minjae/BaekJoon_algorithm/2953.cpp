#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int arr[6]={0};
    int four = 4;
    int k;
    while(four--){
        cin >> k;
        arr[1] += k;
    }
    four = 4;
    while(four--){
        cin >> k;
        arr[2] += k;
    }
    four = 4;
    while(four--){
        cin >> k;
        arr[3] += k;
    }
    four = 4;
    while(four--){
        cin >> k;
        arr[4] +=k;
    }
    four = 4;
    while(four--){
        cin >> k;
        arr[5] += k;
    }

    int max=0,c;
    for(size_t i=1; i<=5; i++){
        if(arr[i] >= max){
            c = i;
            max = arr[i];
        }
    }
    cout << c << " " << arr[c];
}