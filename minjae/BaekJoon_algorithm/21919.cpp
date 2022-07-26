#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check(int n){
    if(n==2)    return true;
    if(n%2 ==0) return false;

    for(int i=3; i*i<=n; i++){
        if(n%i ==0) return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int num,k;
    cin >> num;
    vector<int> V;
    for(int i=0; i<num; i++){
        cin >> k;
        V.push_back(k);
    }    

    V.erase(unique(V.begin(),V.end()),V.end()); // remove same num

    long long res =1;
    for(int i=0; i<V.size(); i++){
        if(check(V[i]) == true){
            res *= V[i];
        }
    }
    if(res == 1)    cout << "-1";
    else            cout << res;
}