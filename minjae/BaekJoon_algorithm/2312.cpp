#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void fun(int n){
    vector<int> V,A;
    for(size_t i=2; i*i<=n; i++){
        while(n%i ==0){
            V.push_back(i); // Factorization
            n /= i;
        }
    }
    if(n>1) V.push_back(n);
    A.clear();
    A.assign(V.begin(),V.end()); // copy vector
    A.erase(unique(A.begin(),A.end()),A.end()); // erase overlap element
    
    int arr[A.size()];
    fill(arr,arr+A.size(),0);

    for(size_t i=0; i<A.size(); i++){
        for(size_t j=0; j<V.size(); j++){
            if(A[i] == V[j]) arr[i]++;
        }
    }

    for(size_t i=0; i<A.size(); i++){
        cout << A[i] << " " << arr[i] << '\n';
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        fun(n);
    }
}