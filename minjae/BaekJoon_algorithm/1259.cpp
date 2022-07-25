#include <iostream>
using namespace std;


bool check(int n){ // check if prime is palindrome num.
    if(n%10 == 0)   return false;
    int tar=0,temp, cmp = n;    
    while(1){
        temp = n%10;
        tar = 10*tar + temp;
        n /= 10;
        if(n == 0)  break;
    }
    if(cmp == tar)  return true;
    else    return false;
}


int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int a;
    while(1){
        cin >> a;
        if (a == 0) break;
        if(check(a) == true)    cout << "yes" << '\n';
        else                    cout << "no" << '\n';
    }
}