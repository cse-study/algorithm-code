#include <iostream>
using namespace std; // 아.. 배열로 짤껄... ㅠㅠ month[12] ={0,31,28,31,30...} 

int main(){
    int m,d,total=0;
    cin >> m >> d;

    if(m == 1)  total += d;
    if(m == 2)  total += 31+d;
    if(m == 3)  total += 59+d;
    if(m == 4)  total += 90+d;
    if(m == 5)  total += 120+d;
    if(m == 6)  total += 151+d;
    if(m == 7)  total += 181+d;
    if(m == 8)  total += 212+d;
    if(m == 9)  total += 243+d;
    if(m == 10)  total += 273+d;
    if(m == 11)  total += 304+d;
    if(m == 12)  total += 334+d;

    if(total%7 ==1) cout << "MON";
    if(total%7 ==2) cout << "TUE";
    if(total%7 ==3) cout << "WED";
    if(total%7 ==4) cout << "THU";
    if(total%7 ==5) cout << "FRI";
    if(total%7 ==6) cout << "SAT";
    if(total%7 ==0) cout << "SUN";
}