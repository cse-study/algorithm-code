#include <iostream>
using namespace std;

int cal(int k){
    int res =0;
    int a,b,c;
    if(k<100){
        res =1;
    }
    if(k>100){
        a = k/100;
        b = (k/10)%10;
        c = k%10;

        if(c-b == b-a){
            res =1;
        }
        else
            res =0;
    }
    return res;
}

int main(){
    int n;
    int sum =0;
    cin >> n;
    for (int i=1; i<=n; ++i){
        sum += cal(i);
    }
    cout << sum;
return 0;
}