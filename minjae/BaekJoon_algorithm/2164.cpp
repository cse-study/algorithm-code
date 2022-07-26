#include <iostream>
#include <list>
using namespace std;

int main(){
    int n;
    cin >> n;

    list<int> L={};
    for(int i=n; i>0; i--){
        L.push_back(i);
    }

    for(int i=0; i<n-1; i++){ // 하나 남겨야하니 n-1 까지 루프돈다.
        L.pop_back();
        int k = L.back();
        L.pop_back();
        L.push_front(k);
    }

    cout << L.front(); // 하나가 남은것 출력
}