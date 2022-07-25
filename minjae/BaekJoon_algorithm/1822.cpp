#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 

vector<int> A,B,ans;
int n1,n2,a;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);

    cin >> n1 >> n2;
    for(int i=0; i<n1; i++){
        cin >> a;
        A.push_back(a);
    }
    for(int i=0; i<n2; i++){
        cin >> a;
        B.push_back(a);
    }

    sort(A.begin(),A.end());
    sort(B.begin(),B.end());

    for(int i=0; i<n1; i++){
        if(binary_search(B.begin(), B.end(), A[i]) == true) continue;
        else        ans.push_back(A[i]);
    }

    cout << ans.size() << '\n';
    for(auto i : ans)    cout << i << " ";
    return 0;
}
