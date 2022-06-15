#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);

    int n,l; cin >> n;
    vector<int> V;
    for(int i=0; i<n; i++){
        cin >> l;
        V.push_back(l);
    }
    sort(V.begin(), V.end());

    vector<int> A;
    for(int i=0; i<n; i++){
        A.push_back(V[i]*(n-i));
    }

    sort(A.begin(), A.end());
    cout << A[n-1] << '\n';

    return 0;
}