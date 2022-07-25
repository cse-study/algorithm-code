#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int a,b,c,m;
    cin >> a >> b >> c >> m;
    if(a > m){
        cout << 0;
        return 0;
    }
    int time=0, work=0, stress=0;
    while(1){
        if(time >=24)   break;
        time++;
        stress += a;
        work += b;
        if(stress + a > m){ // consider maximum work amount
            while(stress - c >=0){
                time++;
                stress -= c;
                if (m-stress > a)   break;
                if(time >=24)   break;
            }
        }
    }
    cout << work;
}