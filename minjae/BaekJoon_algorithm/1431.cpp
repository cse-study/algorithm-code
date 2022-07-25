#include <iostream>
#include <algorithm>
#include <vector>
#include <cctype>
using namespace std;

bool cmp(string& a, string& b){
    if(a.size() != b.size()){ // case different length
        return a.size() < b.size();
    }

    int suma=0, sumb=0; // case same length
    for(int i=0; i<a.size(); i++){
        if(isdigit(a[i])) suma += (a[i] - '0' );
    }
    for(int i=0; i<b.size(); i++){
        if(isdigit(b[i])) sumb += (b[i] - '0' );
    }
    if(suma != sumb)    return suma < sumb;


    return a < b; // dictionally
}

int main(){
    int n; cin >> n;
    vector<string> V;
    string S;
    while(n--){
        cin >> S;
        V.push_back(S);
    }

    sort(V.begin(), V.end(), cmp);
    for(int i=0; i<V.size(); i++){
        cout << V[i] << '\n';
    }

    return 0;
}