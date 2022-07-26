#include <iostream>
#include <cmath>
using namespace std;

int fun(int cnt, int h){
    int res = -6*pow(cnt,4) + h*pow(cnt,3) + 2*pow(cnt,2) + cnt;
    return res;
}

using namespace std;
int main(){
    int h,m,cnt=0;
    cin >> h >> m;
    
    while(1){
        cnt++;
        if(cnt >= m)    break;
        if(fun(cnt,h) <= 0)  {
            cout << "The balloon first touches ground at hour: " << cnt;
            return 0;
        }
    }
    cout << "The balloon does not touch ground in the given time.";
}