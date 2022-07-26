#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 

int m,n,a;
vector<int> V;

bool sol(int x){ 
    if(x == 0)  return true;
    long long cnt =0;
    for(int i=0; i<n; i++){
        cnt += V[i] / x;
    }
    return cnt >= m; // condition satisfy or not
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);

    cin >> m >> n;
    
    for(int i=0; i<n; i++){
        cin >> a;
        V.push_back(a);
    }
    int st =0, en = 1000000000;
    while(st < en){ // binary search
        int mid = (st + en + 1)/2; // +1 해줘야 좀더 안전? 한느낌임
        if(sol(mid))    st = mid; // if condition possible -> then range up
        else            en = mid - 1;
    }
    cout << st;
    return 0;
}