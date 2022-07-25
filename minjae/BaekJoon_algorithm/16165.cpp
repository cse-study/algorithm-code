#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;  


int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    int n,m,mn; cin >> n >> m;
    string group,member;
    unordered_map<string, string> M; // 1인 경우를 위해
    unordered_map<string, vector<string> > G;

    while(n--){
        cin >> group >> mn;
        for(int i=0; i<mn; i++){
            cin >> member;
            M[member] = group;
            G[group].push_back(member);
        }
        sort(G[group].begin(), G[group].end());
    }
    int num; string quiz;
    while(m--){
        cin >> quiz >> num;
        if(num == 1)      cout << M[quiz] << '\n';
        else{
            for(auto i : G[quiz])   cout << i << '\n';
        }
    }
}
    