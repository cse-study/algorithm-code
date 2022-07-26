#include <iostream>
using namespace std; 
long long farr[100] = {0,}; //dp로 푼다.

long long fib(int n){
    if(n == 0)  return farr[0];
    else if(n==1)    return farr[1];

    else if (farr[n]==0)
        farr[n] = fib(n-1) + fib(n-2);
    return farr[n];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    farr[1]=1;
    int n;
    cin >> n;
    cout << fib(n);
}