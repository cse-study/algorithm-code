#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n,t; cin >> n;
    vector<int> a,b;
    for(int i=0; i<n; i++){
        cin >> t;
        a.push_back(t);
    }
    for(int i=0; i<n; i++){
        cin >> t;
        b.push_back(t);
    }
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());
    int sum=0;
    for(int i=0; i<n; i++){
        sum += a[i]*b[i];
    }
    cout << sum;
    return 0;
}