#include<iostream>
using namespace std;

int result (int k, int n){
    if (n == 1){
        return 1;
    }

    if (k == 0){
        return n;
    }
    return result(k-1,n) + result(k,n-1);
}

int main(){
    int t;
    cin >> t;
    for (int i=0; i<t; i++){
        int k,n;
        cin >> k >> n;

        cout << result(k,n) << endl;
    }
    return 0;
}

