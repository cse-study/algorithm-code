#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    int sum=0,find1,find2;
    vector<int> V(9);
    for(size_t i=0; i<9; i++){
        cin >> V[i];
        sum += V[i];
    }
    sum -= 100;

    sort(V.begin(),V.end());
    for(size_t i=0; i<9; i++){
        for(size_t j=0; j<i; j++){
            if(V[i] + V[j] == sum){
                V.erase(V.begin()+i); // cuz i > j, so erase i first
                V.erase(V.begin()+j);
            }
        }
    }

    for(auto k : V)
        cout << k << '\n';
}