#include <iostream>
#include <cmath>
using namespace std; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int a,b,n,k;
    cin >> a >> b;
    cin >> n;

    int val=0,num=0; 
    while(n--){
        cin >> k;
        val += k * pow(a,n); // 10진법으로 실제값 구하기
    }
    for(size_t i=0; i<(long long) pow(10,25); i++){
        if(val <= (long long) pow(b,i)){
            num = i; // b진법으로 몇자리수인지 구함
            break;
        }
    }

    while(num--){
        long long po = pow(b,num);
        cout << val/po << " "; // 하나하나 출력
        val = val %  po;
    }
}