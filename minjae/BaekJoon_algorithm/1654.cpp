#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std; 

int n,k,a;
vector<int> V;

bool sol(long long x){
    long long cur = 0;
    for(int i=0; i<k; i++)  cur += V[i]/x;
    return cur >=n; // possible or not
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);

    cin >> k >> n;
    for(int i=0; i<k; i++){
        cin >> a;
        V.push_back(a);
    }

    long long st = 1, en = pow(2,31)-1;
    while(st < en){ // binary search
        long long mid = (st + en +1)/2;
        if(sol(mid))    st = mid;
        else            en = mid - 1;
    }
    cout << st;
    return 0;
}
