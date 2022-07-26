#include <iostream>
#include <vector>
using namespace std;

int arr[1000005]={0};
vector<int> V;

void make(){
    for(int i=2; i<=1000000; i++){
        arr[i]=i;
    }
    for(int i=2; i*i<=1000000; i++){
        if(arr[i] == 0) continue;
        for(int j=2*i; j<=1000000; j+=i)    arr[j]=0;
    }
    for(int i=2; i<=1000000; i++){
        if(arr[i] != 0) V.push_back(arr[i]);
    }

}

int GB(int n){
    int cnt=0,k=0;
    
    while(1){ // for time limitation. think it!!
        if(V[k] > n/2)  break; // avoid overlap. (3+17, 17+3)
        if(arr[(n-V[k])])   cnt++; // if(arr[n-v[k]] == prime m) -> cnt++;
        k++;
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t,n;
    cin >> t;
    make();
    while(t--){
        cin >> n;
        cout << GB(n) << '\n';
    }
}