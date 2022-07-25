#include <iostream>
using namespace std; // cuz memory problem, we can't use eratosthenes sieve

bool prime(int n){
    for(int i=2; i*i<=n; i++){
        if(n%i==0)  return false;
    }
    return true;
}

void fun(int num, int len, int N){
    if(len == N){
        cout << num << '\n'; // cout
        return;
    }
    for(int i=1; i<10; i+=2){ // can only odd num
        if(prime(num*10 + i))   fun(num*10 + i, len+1, N);
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    fun(2,1,n); // can only 2,3,5,7
    fun(3,1,n);
    fun(5,1,n);
    fun(7,1,n);
}