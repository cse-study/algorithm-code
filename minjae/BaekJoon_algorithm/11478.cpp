#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;  

set<string> S;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    string A,st = "";
    cin >> A;
    for(int i=0; i<A.size(); i++){
        for(int j=i; j<A.size(); j++){
            st += A[j];
            S.insert(st);
        }
        st = "";
    }
    cout << S.size();

}
    