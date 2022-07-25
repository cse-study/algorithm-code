#include <iostream>
#include <cmath>
using namespace std;

int ela(int n, int k){ // 보통 에라토스랑 다르다. 문제에따라 변형필요
    int c=0;
    int arr[n];
    for(size_t i=2; i<=n; i++)
        arr[i] = i;
    for(size_t i=2; i<=n; i++){
        if(arr[i]==0)
            continue;
        for(int j=i; j<=n; j+=i){
            if(arr[j]!=0){
                arr[j]=0;
                c++;
                if(c == k){
                    return j;
                }
            }
        }
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n,k;
    cin >> n >> k;
    cout << ela(n,k);
    
}