#include <iostream>
#include <string>
#include <algorithm> // 합이 3의 배수이면 내림차순으로 정렬해서 출력한다.
using namespace std; //10의 배수이기 위해서는 0이 있어야하고 각자릿수의 합이 3의 배수여야 한다.

void fun (string n){
    int sum=0, arr[n.size()];
    long result=0;
    for(size_t i=0; i<n.size(); i++){
        arr[i] = n[i]-'0';
    }

    sort(arr, arr+n.size());

    for(size_t i=0; i<n.size(); i++){
        sum +=arr[i];
    }

    if(arr[0] != 0){
        cout << "-1";

    }

    else if(sum%3 != 0)  {
        cout << "-1";
    }
    else{
        for(int i=n.size()-1; i>=0; i--){
            cout << arr[i]; // 엄청 큰수임으로 int로출력이 아니라 배열로 한자리씩 출력한다.
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string n;
    cin >> n;
    fun(n);
    
}