#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std; 

// 투포인터 이용
int n,a,ans1=1e9+1,ans2=1e9+1;
vector<int> V;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a;
        V.push_back(a);
    }
    int st=0, en = n-1;
    while(st < en){
        if(abs(ans1+ans2) > abs(V[st]+V[en])){
            ans1 = V[st];
            ans2 = V[en];
        }
        if(abs(V[st]+V[en-1]) <= abs(V[st+1] + V[en]))   en = en -1;
        else                                             st = st+1;
    }
    cout << ans1 << " " << ans2;
    
    return 0;
}