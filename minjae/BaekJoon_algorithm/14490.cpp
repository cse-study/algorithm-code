#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int a,b;
    string s,temp;
    cin >> s;
    
    int k=0;
    while(1){
        if(s[k] == ':'){
            temp = s.substr(0,k);
            a = stoi(temp);
            temp = s.substr(k+1,s.size());
            b = stoi(temp);
            break;
        }
        k++;
    }

    for(size_t i=min(a,b); i >= 2; i--){
        if(a%i == 0 && b%i == 0){
            a /= i;
            b /= i;
        }
    }
    cout << a << ":" << b;
}