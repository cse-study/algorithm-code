#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 

vector<int> V; // 함수에 넣어주니 할때마다 복사해서 시간초과 남. 앞으로 변수는 빼주자.

bool check(int tar){
    int st=0, end=V.size()-1;
    while(st <= end){
        int mid = (st + end)/2;
        if(V[mid] < tar)        st = mid + 1;
        else if (V[mid] > tar)  end = mid -1;
        else                    return 1; // 찾은경우
    }
    return 0; // 없는경우
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);

    int n1,n2,a; cin >> n1;
    for(int i=0; i<n1; i++){
        cin >> a;
        V.push_back(a);
    }
    sort(V.begin(), V.end());

    cin >> n2;
    for(int i=0; i<n2; i++){
        cin >> a;
        cout << check(a) << '\n'; // 직접구현말고 binary_search함수도 사용가능
        // cout << binary_search(V.begin(), V.end(), a) << '\n';
    }

    return 0;
}