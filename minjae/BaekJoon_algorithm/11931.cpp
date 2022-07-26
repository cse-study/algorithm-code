#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int mxn = 2000000, half = mxn/2;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);

    vector<bool> isnum(mxn + 2);
    int n,t;
    cin >> n;
    while(n--){
        cin >> t;
        isnum[t + half] = true;
    }
    for(int i = mxn; i >= 0; i--){
        if(isnum[i]) cout << i - half << '\n';
    }

    return 0;
}