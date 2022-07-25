#include <iostream>
using namespace std;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int sum=0,k;
    for(size_t i=1; i<=5; i++){
        cin >> k;
        sum +=k;
    }
    cout << sum;
}