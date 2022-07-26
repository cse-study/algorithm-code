#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int mxn = 200000, half = mxn/2;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);

    vector<int> isnum(mxn + 2);
    int n,t;
    cin >> n;
    while(n--){
        cin >> t;
        isnum[t + half]++;
    }
    for(int i = half; i <= mxn; i++){
        if(isnum[i] > 0){
            while(isnum[i]){
                isnum[i]--;
                cout << i - half << '\n';
            }
        }
    }
    return 0;
}