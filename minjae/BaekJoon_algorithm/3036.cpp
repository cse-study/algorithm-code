#include <iostream>
#include <string>
using namespace std;

int gcd(int a, int b){ // 유클리드 알고리즘 gcd구하기
    if(b==0)
        return a;
    else    
        return gcd(b, a%b);
}

string make(int a, int b){ // 출력 모양 make
    int k = gcd(a,b);
    a /= k;
    b /= k;
    string result = to_string(a) + "/" + to_string(b); // string으로 전환
    return result;
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(size_t i=0; i<n; i++){
        cin >> arr[i];
    }
    
    for(size_t i=1; i<n; i++){
        cout << make(arr[0], arr[i]) << '\n';
    }

}