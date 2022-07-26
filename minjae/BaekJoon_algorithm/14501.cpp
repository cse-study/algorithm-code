#include <iostream>
#include <algorithm>
using namespace std; // using recursion, brute force

int res=0;
int n;
int d[16] ={0}, m[16]={0};

void func(int now, int sum, int num){
    if(now == n+1){ // end of mission
        res = max(res, sum);
        return;
    }
    else if (now > n+1){ // extended day
        res = max(res, sum-num);
        return;
    }

    for(size_t i = now + d[now]; i<= n+d[now]; i++) // recursion, // i = now + spend day
        func(i, sum+m[now], m[now]);
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    cin >> n;
    for(size_t i=1; i<=n; i++){
        cin >> d[i] >> m[i];
    }
    for(size_t i=1; i<=n; i++){
        func(i,0,0);
    }
    cout << res;
}