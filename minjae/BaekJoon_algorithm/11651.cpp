#include <iostream>
#include <vector>
#include<utility>
#include<algorithm>
using namespace std;

int main(){
ios::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

    int n;
    cin >> n;
    vector <pair<int,int>> v(n);

    for (int i=0; i<n; i++){
        cin >> v[i].second >> v[i].first;
    }

    sort(v.begin(), v.end());

    for(int i=0; i<n; i++){
        cout << v[i].second << " " << v[i].first << "\n";
    }
}