#include <iostream>
using namespace std;

int n,m;
int arr[9] = {0};
bool visited[9] = {0};

void fun(int cnt)
{
    if(cnt == m){
        for(int i =0; i<m; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    int start = 1;
    if(cnt != 0)  start = arr[cnt-1] + 1; // 21 X, 22 X, 23 O, 24 O, so start is arr[k-1]+1
    for(int i=start; i<=n; i++){
        if(!visited[i]){
            visited[i] = true;
            arr[cnt] = i;
            fun(cnt +1);
            visited[i] = false;
        }
    }
}


int main(){
    cin >> n >> m;
    fun(0);

    return 0;
}