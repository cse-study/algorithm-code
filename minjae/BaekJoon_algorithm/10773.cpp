#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack<int> S;
    int n;
    cin >> n;
    int k;
    while(n--){
        cin >> k;
        if(k != 0)
            S.push(k);
        else
            S.pop();
    }

    int sum=0;

    while(!S.empty()){
        sum += S.top();
        S.pop();  
    }
    cout << sum;
}