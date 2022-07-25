#include <iostream> 
using namespace std;

int gcd(int a, int b){
    if(b==0)    return a;
    else{
        return gcd(b,a%b);
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n,a,b;
    cin >> n;
    while(n--){
        cin >> a >> b;
        cout << a*b/gcd(a,b) << " " << gcd(a,b) << '\n'; // lcd = ab/gcd
    }
}