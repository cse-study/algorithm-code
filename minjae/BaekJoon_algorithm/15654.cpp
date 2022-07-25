#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int arr[9] = {0};
int getn[9] = {0};
bool visited[9] = {0};

void fun(int cnt){
    if(cnt == m){
        for(int i =0; i<m; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    
    for(int i=0; i<n; i++){
        if(!visited[i]){
            visited[i] = true;
            arr[cnt] = getn[i];
            fun(cnt +1);
            visited[i] = false;
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> getn[i];
    }
    sort(getn, getn+n);
    fun(0);
    return 0;
}