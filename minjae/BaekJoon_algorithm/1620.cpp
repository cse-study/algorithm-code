#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <cctype>
using namespace std;  

int n,m;
string S[100005];
unordered_map<string, int> M;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    cin >> n >> m;
    for(int i=1; i<=n; i++){ // i 실수 조심!
        cin >> S[i];
        M[S[i]]=i; // unordered_map 원소 저장방법이다. m[string] = int
    }
    for(int i=0; i<m; i++){
        string T;
        cin >> T;
        if(isdigit(T[0])){
            cout << S[stoi(T)] << '\n';
        }
        else{
            cout << M[T] << '\n';
        }
    }
}
    