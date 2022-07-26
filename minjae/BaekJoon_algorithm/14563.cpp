#include <iostream>
#include <string>
using namespace std;

int sum(int k){
    int sum=0;
    for(size_t i=1; i<k; i++){
        if(k%i == 0)    sum+= i;
    }
    return sum;
}

string fun(int k){
    string res;
    if(sum(k) == k)         res = "Perfect";
    if(sum(k) > k)          res = "Abundant";
    if(sum(k) < k)          res = "Deficient";
    return res;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int num,k;
    cin >> num;
    while(num--){
        cin >> k;
        cout << fun(k) << '\n';
    }
}