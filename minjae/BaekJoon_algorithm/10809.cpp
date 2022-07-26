#include <iostream>
#include <string>
using namespace std;

int main(){
    string a = "abcdefghijklmnopqrstuvwxyz";
    string word;
    cin >> word;

    for (int i=0; i<a.length(); ++i){
        cout << (int)word.find(a[i]) << " ";
    }
}