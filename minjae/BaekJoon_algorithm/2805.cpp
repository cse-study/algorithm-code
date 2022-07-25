#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 

int n,m,a;
vector<int> V;

bool sol(int x){ // x만큼 자른다
    long long cur = 0;
    for(int i=0; i<n; i++){
        if(V[i] <= x)   continue; // 자를 길이가 안되는 경우
        cur += V[i] - x; // 자르고 남은것들을 모아서 들고간다.
    }
    return cur >= m;
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);

    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> a;
        V.push_back(a);
    }
    sort(V.begin(), V.end());
    int st=0, en = V[n-1];
    while(st < en){
        int mid = (st + en + 1)/2;
        if(sol(mid))    st = mid;
        else            en = mid-1;
    }
    cout << st;
    return 0;
}