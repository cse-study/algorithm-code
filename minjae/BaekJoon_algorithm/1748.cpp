#include <iostream> 
#include <cmath>
using namespace std;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    long num,cnt=0,ans=0,temp=0;
    cin >> num;

    int ori = num;
    num *=10;
    while(num/10){
        num /=10;
        cnt++; // cnt is number of digit
    }

    for(int i=1; i<cnt; i++){ // 9*1 + 90*2 + 900*3 + ....
        ans += 9*pow(10,i-1) * i;
    }
    ori -= pow(10,cnt-1)-1; // remain val (12837 - 9999) * 5
    ans += ori * cnt;
    cout << ans;
}