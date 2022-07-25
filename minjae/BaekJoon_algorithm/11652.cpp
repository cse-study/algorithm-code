#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; // long long 확인잘하자..

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);

    long long n,t; cin >> n;
    vector<long long> V;
    while(n--){
        cin >> t;
        V.push_back(t);
    }
    sort(V.begin(), V.end());
    long long c=1, mc=1, val;
    bool check = false;
    for(int i=0; i< V.size()-1; i++){
        if(V[i] == V[i+1]){
            c++;
            if(mc < c){
                mc = c;
                val = V[i];
                check = true;
            }
        }
        if(V[i] != V[i+1])  c=1;
    }
    if(check == false){
        cout << V[0] << '\n'; 
    }
    else{
        cout << val << '\n';
    }

    return 0;
}