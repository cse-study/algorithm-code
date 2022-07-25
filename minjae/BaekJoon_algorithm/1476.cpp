#include <iostream>
using namespace std;

// 중국인의 나머지 정리이다. 숫자가 작음으로 그냥 바로 ++으로 푼다.
int main(){
    int a,b,c;
    cin >> a >> b >> c;

    int year=1;
    while(1){
        if((year-a)%15 == 0 && (year-b)%28 == 0 && (year-c)%19 == 0){
            break;
        }
        year++;
    }
    cout << year;
}