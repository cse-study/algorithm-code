#include <iostream>
#include <vector>
#include<utility>
#include<algorithm>
#include<string>
using namespace std;

int main(){
ios::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

    int n;
    cin >> n;
    vector <pair<int,string>> v;
    string temp;

    for (int i=0; i<n; i++){
        string a;
        cin >> a;
        v.push_back(pair<int,string>(a.size(),a));
    }

    sort(v.begin(),v.end());

    for(int i=0; i<n; i++){
        if (temp == v[i].second) {
            continue;
        }
        cout << v[i].second << "\n";
        temp = v[i].second;
    }

    return 0;
}