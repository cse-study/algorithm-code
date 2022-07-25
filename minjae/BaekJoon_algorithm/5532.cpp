#include <iostream> 
using namespace std;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int l,a,b,c,d;
    cin >> l >> a >> b >> c >> d;
    int math, kor;
    if(a%c ==0) math = a/c;
    else        math = a/c+1;
    if(b%d==0)  kor = b/d;
    else        kor = b/d+1;

    cout << l - max(math,kor);
}