#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 

// a + b + c = d => (a + b) = (d - c) 를 이용
int a[1003];
vector<int> AB;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);

    int n; cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a, a+n);
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++)
            AB.push_back(a[i]+a[j]); // 두수의 합 모든 경우의수를 벡터에 추가
    }
    sort(AB.begin(), AB.end());
    for(int i=n-1; i>=0; i--){ // 최댓값을 착는것이고, 정렬되있기 때문에 n-1부터 찾는다.
        for(int j=0; j<i; j++){
            if(binary_search(AB.begin(), AB.end(), a[i]-a[j])){ // d - c를 찾는 과정
                cout << a[i]; return 0; // d 를 출력
            }
        }
    }
}