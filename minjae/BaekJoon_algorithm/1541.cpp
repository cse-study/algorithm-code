#include <iostream>
#include <algorithm>
#include <string>
using namespace std; 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);

    string s;
    int ans=0, temp=0;
    int sign =1;
    cin >> s;
    for(char c : s){
        if(c == '+' || c == '-'){
            ans += temp * sign;
            if(c == '-')    sign = -1; // 처음 - 가 나오고부터는 그리디로인해 전부 - 값을 가진다
            temp = 0; // 부호가 오면 숫자 초기화
        }
        else{
            temp *= 10; // 부호가 나오지 않을시, 자릿수 올라가는것 표현
            temp += c - '0';
        }
    }
    ans += temp * sign; // 마지막은 부호가아니라 연산처리 못해서 for문 끝나고 해줌
    cout << ans;
    return 0;
}