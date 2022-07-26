#include <iostream>
#include <string>
using namespace std; 

bool prime(int n){
    if(n==1)    return true; // 1인데도 소수라고 해야 풀리넹...
    else{
        for(size_t i=2; i*i<=n; i++){
            if(n%i == 0)    return false;
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string a;
    cin >> a;

    int val=0;
    for(size_t i=0; i<a.size(); i++){
        if(a[i]>='a' && a[i]<='z'){
            val += (a[i]-'a'+1); // a = 1 임으로  +1을 해준다
        }
        else{
            val += (a[i]-'A'+1);
        }
    }
    bool check = prime(val);
    if (check == 0)
        cout << "It is not a prime word." << '\n';
    else
        cout << "It is a prime word." << '\n';
}