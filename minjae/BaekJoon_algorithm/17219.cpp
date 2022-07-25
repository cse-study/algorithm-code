#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;  

unordered_map<string, string> M;
int n,m;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    cin >> n >> m;
    string A,B;
    for(int i=0; i<n; i++){
        cin >> A >> B;
        M[A] = B;
    }
    for(int i=0; i<m; i++){
        cin >> A;
        cout << M[A] << '\n';
    }
}
    