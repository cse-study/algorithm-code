#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n; cin >> n;
    int a;
    int c =0;

    vector <int> v;
    while(1){
        a = n%10;
        v.push_back(a);

        n = n/10;
        c = c +1;
        if (n==0){
            break;
        }
    }

    sort(v.begin(),v.end(), greater<>());
    for(int i=0; i<c; i++){
        cout << v[i];
    }

    return 0;
}