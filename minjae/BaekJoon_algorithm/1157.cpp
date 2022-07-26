#include <iostream>
#include <string>
using namespace std;

int main(){
    string a;
    cin >> a;

    int arr[26] = {0};
    int max_c = 0;
    int ind = 0;
    int c = 0;
    
    for(int i =0; i<a.length(); ++i){
        int n = a.at(i);
        if(n<97)
            arr[n-65]++;
        else
            arr[n-97]++;
    }

    for (int i =0; i<26; ++i){
        if(max_c < arr[i]){
            max_c = arr[i];
            ind =i;
        }
    }

    for (int i =0; i<26; ++i){
        if (max_c == arr[i])
            c += 1;
    }

    if (c == 1){
        cout << (char)(ind+65) << endl;
        return 0;
    }
    
    else
        cout << "?" << endl;

    return 0;
}