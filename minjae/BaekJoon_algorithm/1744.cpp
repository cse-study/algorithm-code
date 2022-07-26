#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std; 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    long res = 0;
    int n; cin >> n;
    vector<int> V1,V2;
    for(int i=0; i<n; i++){
        int t; cin >> t;
        if(t ==1)   res++; // very very important -> 1 처리 중요!
        else if(t>1) V1.push_back(t); // 양수끼리
        else    V2.push_back(t); // 0, 음수끼리
    }
    sort(V1.begin(), V1.end());
    sort(V2.begin(), V2.end());
    reverse(V1.begin(), V1.end());
    //reverse(V2.begin(), V2.end()); 음수들은 sort 필요없다

    if(V1.size() % 2 == 0){
        for(int i=0; i<V1.size(); i += 2){
            res += V1[i]*V1[i+1];
        }
    }
    else{
        for(int i=0; i<V1.size()-1; i += 2){
            res += V1[i]*V1[i+1];
        }
        res += V1[V1.size()-1];
    }

    if(V2.size() % 2 == 0){
        for(int i=0; i<V2.size(); i += 2){
            res += V2[i]*V2[i+1];
        }
    }
    else{
        for(int i=0; i<V2.size()-1; i += 2){
            res += V2[i]*V2[i+1];
        }
        res += V2[V2.size()-1];
    }
    cout << res;
    return 0;
}