#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int gcd_fun(int a, int b){ // 유클리드 알고
    if(b == 0)
        return a;
    else
        return gcd_fun(b, a%b);
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(size_t i=0; i<n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    int gcd = v[1] - v[0]; // 나머지가 같을경우 나머지가 사라지고 m으로 묶인다.

    for(size_t i = 2; i < n; i++){
        gcd = gcd_fun(gcd, v[i]-v[i-1]); // 입력받은 모든수의 gcd 를 구함
    }

    vector<int> r;

    for(size_t i = 2; i*i <= gcd; i++){ // 약수는 sqrt 까지만 구한다.
        if(gcd % i == 0){
            if(i == gcd/i)
                r.push_back(i); // 중복된 경우 는 하나만 입력
            else{
                r.push_back(i); // for문을 작게 돌리게 하기위해서
                r.push_back(gcd / i);
            }
        }
    }
    
    sort(r.begin(), r.end());
    
    for(size_t i=0; i<r.size(); i++){
        cout << r[i] <<" ";
    }
    cout << gcd; // 마지막은 최대공약수 자체가 제일크고 마지막에 출력
    
}