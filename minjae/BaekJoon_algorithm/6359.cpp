#include <iostream> 
using namespace std;

int fun(int k){
    int count=0;
    bool arr[k+1];
    for(size_t i=0; i<=k; i++){
        arr[i]=true;
    }
    for(int i=2; i<=k; i++){
        for(int j=i; j<=k; j+=i){
            arr[j] = !arr[j];
        }
    }

    for(size_t i=1; i<=k; i++){
        if(arr[i] == true)  
            count++;
    }
    return count;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n,k;
    cin >> n;
    for(size_t i=0; i<n; i++){
        cin >> k;
        cout << fun(k) << '\n';
    }
    
}