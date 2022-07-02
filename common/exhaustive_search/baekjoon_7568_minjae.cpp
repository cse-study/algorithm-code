#include<iostream>
using namespace std;

int main(){
    int res[51]={0};
    int n,a,b;
    pair<int,int> h[51];

        cin >> n;
        for(int i=0; i<n; i++){
            cin>> a >> b;
            h[i] = {a,b};
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==j){
                    continue;
                }
                if(h[i].first > h[j].first && h[i].second > h[j].second){
                    res[j] = res[j]+1;
                }
            }
        }
        for(int i=0; i<n; i++){
            cout << res[i] + 1 << " ";
        }
        return 0;
}