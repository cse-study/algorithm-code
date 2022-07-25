#include <iostream>
#include <cmath>
using namespace std;

int main(){
    long long a;
    cin >> a;
    
    for(long long i=0; i<= 1000000000; i++){
        if(i*i + i == a*2){
            cout << i;
            return 0;
        }
        if(i*i + i > a*2){
            cout << i-1;
            return 0;
        }
    }
}