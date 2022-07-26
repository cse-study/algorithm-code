#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
ios::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

    int n,t;
    cin >> n;
    vector <int> a;
    for(int i=0; i<n; i++){
        cin >> t;
        a.push_back(t);
    }

    sort(a.begin(),a.end());

    for(int i=0; i<n; i++){
        cout << a[i] << '\n';
    }

    return 0;
}