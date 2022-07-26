#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int a,b,c,d,e;
    cin >> a >> b >> c >> d >> e;
    
    int cnt = c + d + e;
    a -= d; // 1kg match to 4kg.
    b -= c; // 2kg match to 3kg

    if(a >=0 && b >=0){
        if ( b%2 ==0 ){
            cnt+= b/2;
            a -= b/2;
        }
        else{
            cnt+= b/2 +1;
            a -= (b/2 + 3);
        }
        if(a>0){
            if (a%5 == 0)   cnt += a/5;
            else            cnt += a/5+1;
        }           
    }
    else if (a >=0 && b < 0){
        if(a + 2*b > 0){
            a += 2*b;
            if(a>0){
            if (a%5 == 0)   cnt += a/5;
            else            cnt += a/5+1;
        }
        }   
    }
    else if (a < 0 && b >= 0){
        if ( b%2 ==0 )      cnt+= b/2;
        else                cnt+= b/2 +1;
    }
    // a<0 b <0 is not matter.
    cout << cnt;
}