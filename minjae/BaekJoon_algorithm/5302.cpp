#include <iostream>
using namespace std;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int a,b,c,q=0;
    cin >> a >> b >> c;

    int res = (a+b)/c;
    q = (a+b) % c + res; // 바꿔서 먹고 남은병도 사용
    while(q>=c){
        res += q/c;
        q = q % c + (q / c);
    }

    cout << res;
}