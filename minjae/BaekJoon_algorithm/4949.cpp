#include <iostream>
#include <string>
#include <stack> // 괄로를 스택을 이용해 넣고, 매칭되면 뺴고 이런식으로 확인
using namespace std; 


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string a;
    while(1){
        stack<char> S;
        getline(cin, a);
        if(a == ".")    break;
        bool check = true;
        for(size_t i=0; i<a.size(); i++){
            if(a[i] == '(' || a[i] == '[') // 과로 여는거 오면 추가
                S.push(a[i]);
            else if(a[i] == ')'){ // 과로 닫는거 왔을때 조건 맞으면 쌍 제거 아니면 false
                if(S.empty() || S.top() != '('){
                    check = false; 
                    break;
                }
                S.pop();                
            }
            else if(a[i] == ']'){
                if(S.empty() || S.top() != '['){
                    check = false; 
                    break;
                }
                S.pop();                
            }
        }
        if(!S.empty())  check = false;     //쌍이 다 맞아 비였으면 true
        if(check == true)   cout << "yes" << '\n';
        else    cout << "no" << '\n';
    }    
    
}