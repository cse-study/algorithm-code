#include <iostream>
#include <vector>
using namespace std;

int fun(int n){
    vector<int> V;
    vector<int> P;
    int cnt=0,sum=0;

    for(size_t i=0; i<=n; i++){
        V.push_back(i);
    }
    for(size_t i=2; i*i<=n; i++){
        if(V[i] == 0)   continue;
        for(size_t j=2*i; j<=n; j+=i){
            V[j] = 0;
        }
    }
    for(size_t i=2; i<=n; i++){
        if(V[i] != 0){
            P.push_back(V[i]);
        }   
    }
    
    int lo=0, hi=0; // using two pointer algorithm O(N^2) -> O(N)
    while(1){
        if(sum >= n){
            sum -= P[lo++];
        } else if (hi == P.size()){
            break;
        } else{
            sum += P[hi++];
        }
        if(sum == n)    cnt++;
    }

    return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    cout << fun(n);
}