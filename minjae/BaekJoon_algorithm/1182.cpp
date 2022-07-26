#include <bits/stdc++.h>
using namespace std;

int n, s;
int cnt=0;
int arr[30];

void fun(int cur, int tot){
    if(cur == n){ // base condition
        if(tot == s){   
            cnt++;
        }
        return;
    }
    fun(cur+1, tot);
    fun(cur+1, tot+arr[cur]);
}


int main(void){
    cin >> n >> s;
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }

    fun(0,0);
    if(s == 0)  cnt--; 
    cout << cnt << endl;
    return 0;
}