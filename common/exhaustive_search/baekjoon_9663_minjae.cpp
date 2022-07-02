#include <bits/stdc++.h>
using namespace std;
int n;
int cnt=0;
bool check1 [40];
bool check2 [40];
bool check3 [40];
void queen(int res){
    if(res == n){
        cnt++;
        return;
    }
    for(int i=0; i<n; i++){
        if(check1[i] || check2[i+res] || check3[res-i+n-1])
            continue;
        check1[i]=1;
        check2[res+i]=1;
        check3[res-i+n-1]=1;
        queen(res+1);
        check1[i] = 0;
        check2[res + i] = 0;
        check3[res - i + n - 1] = 0;
    }
}
int main(void){
    cin >> n;
    queen(0);
    cout << cnt << endl;
    return 0;
}