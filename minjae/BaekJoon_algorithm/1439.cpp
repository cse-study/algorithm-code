#include <iostream>
#include <algorithm>
#include <string>
using namespace std; 

int main(){ 
    string s; cin >> s;
    int cnt = 0;
    for(int i=0; i<s.size()-1; i++){
        if(s[i] != s[i+1])  cnt++;
    }
    if(cnt % 2 == 0)    cout << cnt/2;
    else                cout << cnt/2 + 1;
}