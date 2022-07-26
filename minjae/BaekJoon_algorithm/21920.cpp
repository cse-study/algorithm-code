#include <iostream>
#include <vector>
using namespace std;

int GCD(int a, int b){
    if(b == 0)  return a;
    else        return GCD(b,a%b);
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int num,k,cmp,cnt=0;
    double sum=0;
    cin >> num;
    vector<int> V;
    for(int i=0; i<num; i++){
        cin >> k;
        V.push_back(k);
    }    
    cin >> cmp;
    for(int i=0; i<num; i++){
        if(GCD(cmp,V[i]) == 1){
            cnt++;
            sum += V[i];
        }
    }   
    cout << sum/cnt;
}