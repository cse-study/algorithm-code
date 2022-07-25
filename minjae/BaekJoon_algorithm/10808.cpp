#include <iostream>
using namespace std;

int main(){
    int freq[26]={0,};
    string s;
    cin >> s;

    for(auto c : s)
        freq[c-'a']++;
    for(size_t i=0; i<26; i++){
        cout << freq[i] << " ";
    }

    return 0;
}