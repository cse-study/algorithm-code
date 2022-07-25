#include <iostream> 
#include <vector>
using namespace std;

void fun(int n){
    int sum=0;
    vector<int> V;
    
    for(int i=1; i<n; i++){
        if(n%i ==0){
            V.push_back(i);
        }
    }
    for(auto a : V){
        sum += a;
    }

    if(sum == n){
        cout << n << " = ";
        for(size_t i=0; i<V.size()-1; i++){
            cout << V[i] << " + ";
        }
        cout << V[V.size()-1] <<'\n';
    }
    else{
        cout << n << " is NOT perfect.\n";
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    while(1){
        cin >> n;
        if(n == -1) break;
        fun(n);
    }
}