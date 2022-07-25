#include <iostream>
#include <algorithm>
using namespace std; 

int main(){
    int a;
    cin >> a;
    for(size_t i = a; i>0; i--){
        for(size_t j=i; j>0; j--){
            cout << "*";
        }
        cout << '\n';
    }
}