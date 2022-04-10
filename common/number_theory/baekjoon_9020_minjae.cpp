#include <iostream>
#include <cmath>
using namespace std;


bool prime(int a){ // 소수판별
    if (a <=1)  return 0;
    for(size_t i=2; i<=static_cast<int>(sqrt(a)); i++){
        if(a%i==0)  return 0;
    }
    return 1;
}

int main(){
    int n;
    cin >> n;
    for(size_t i=0; i<n; i++){
        int a;
        cin >> a;
        for(int i = a/2; i<a; i++){
            if(prime(i) == 1 && prime(a-i)==1){
                cout << a-i << " " << i <<'\n';
                break;
            }
        }
    }
    return 0;
}