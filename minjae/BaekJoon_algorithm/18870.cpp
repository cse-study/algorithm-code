#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,a;
    cin >> n;
    vector<int> vec;
    vector<int> test;
    for(int i=0; i<n; i++){
        cin >> a;
        vec.push_back(a);
        test.push_back(a);
    }
    sort(vec.begin(), vec.end()); // sort for binary search
    vec.erase(unique(vec.begin(), vec.end()), vec.end()); // check write small case. for avoid duplication

    for(int i = 0; i < n; i++) {
        cout << lower_bound(vec.begin(), vec.end(), test[i]) - vec.begin() << " "; // binary search
    }
    return 0;
}