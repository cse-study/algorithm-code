#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    int n,a,c=0;
    cin >> n;
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
}