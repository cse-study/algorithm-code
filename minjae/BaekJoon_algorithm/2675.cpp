#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    cin>> n;
    for (int i=0; i<n; ++i){
        string word;
        int c;
        cin >> c >> word;
        
        for(int k=0; k<word.length(); ++k){
            for (int j=0; j<c; ++j){
                cout << word[k];
            }
        }
        cout << endl;
    }

}