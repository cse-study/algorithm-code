#include <iostream>
using namespace std;

bool fun(string a){ // check group word
    int len = a.size();
    for(size_t i=0; i<len-1; i++){
        for(size_t j=i+2; j<len; j++){
            if(a.at(i) != a.at(i+1) && a.at(i) == a.at(j))  return 0;
        }
    }
    return 1;
}

int main(){
    int n;
    cin >> n;

    int res=0;
    for(size_t i=0; i<n; i++){
        string a;
        cin >> a;
        if(fun(a) == 1) res+=1;
    }

    cout << res;
    return 0;
}